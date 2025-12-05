
# 强制使用小写盘符，因为 CPH 插件通常使用小写盘符计算哈希
function Get-NormalizedPath($path) {
    if ($path.Length -gt 1 -and $path[1] -eq ':') {
        return $path.Substring(0, 1).ToLower() + $path.Substring(1)
    }
    return $path
}

$md5 = [System.Security.Cryptography.MD5]::Create()
function Get-MD5($inputString) {
    $bytes = [System.Text.Encoding]::UTF8.GetBytes($inputString)
    return [BitConverter]::ToString($md5.ComputeHash($bytes)).Replace("-", "").ToLower()
}

$rootDir = Get-Location
Write-Host "Working in: $rootDir"

# 获取根目录下所有以数字开头的 cpp 文件 (假设是 CF 题目)
$files = Get-ChildItem -Path . -Filter "*.cpp" | Where-Object { $_.Name -match "^(\d+)" }

foreach ($file in $files) {
    $contestId = $matches[1]
    $fileName = $file.Name
    
    # 1. 准备目标文件夹
    if (-not (Test-Path $contestId)) {
        New-Item -ItemType Directory -Path $contestId | Out-Null
        Write-Host "Created directory: $contestId"
    }
    
    # 2. 计算移动后的新路径和新哈希
    $targetDir = Join-Path $rootDir $contestId
    $targetPath = Join-Path $targetDir $fileName
    $normalizedTargetPath = Get-NormalizedPath $targetPath
    $newHash = Get-MD5 $normalizedTargetPath
    
    # 3. 处理 CPH 配置文件
    # CPH 配置文件通常在根目录的 .cph 下，格式为 .文件名_旧哈希.prob
    if (Test-Path ".cph") {
        $probPattern = "." + $fileName + "_*.prob"
        $probFiles = Get-ChildItem -Path ".cph" -Filter $probPattern
        
        foreach ($prob in $probFiles) {
            # 读取并更新配置文件内容
            try {
                $json = Get-Content -Path $prob.FullName -Raw | ConvertFrom-Json
                $json.srcPath = $normalizedTargetPath
                
                # 保存更新后的内容
                $json | ConvertTo-Json -Depth 100 -Compress | Set-Content -Path $prob.FullName
                
                # 重命名配置文件 (使用新哈希)
                $newProbName = "." + $fileName + "_" + $newHash + ".prob"
                $renamedProbPath = Join-Path $prob.Directory.FullName $newProbName
                if ($prob.Name -ne $newProbName) {
                    Rename-Item -Path $prob.FullName -NewName $newProbName
                }
                
                # 移动配置文件到子目录的 .cph 文件夹
                $targetCphDir = Join-Path $targetDir ".cph"
                if (-not (Test-Path $targetCphDir)) {
                    New-Item -ItemType Directory -Path $targetCphDir | Out-Null
                }
                
                Move-Item -Path $renamedProbPath -Destination $targetCphDir -Force
                Write-Host "Processed config for $fileName"
            }
            catch {
                Write-Warning "Failed to process config for $($file.Name): $_"
            }
        }
    }
    
    # 4. 移动源代码文件
    Move-Item -Path $file.FullName -Destination $targetDir -Force
    Write-Host "Moved $fileName -> $contestId\$fileName"
}

# 处理可能存在的 zip 文件
Get-ChildItem -Path . -Filter "*.zip" | Where-Object { $_.Name -match "^(\d+)" } | ForEach-Object {
    $cid = $matches[1]
    if (Test-Path $cid) {
        Move-Item -Path $_.FullName -Destination $cid -Force
    }
}
