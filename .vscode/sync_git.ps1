# Run the organizer first to ensure files are in correct folders
Write-Host "Organizing files..."
& "$PSScriptRoot\organize_contest.ps1"

# Set location to workspace root
Set-Location "$PSScriptRoot\.."

# Check if there are changes
if (-not (git status --porcelain)) {
    Write-Host "No changes to commit."
    exit
}

# Try to detect the contest ID from recently modified files
$recentFile = Get-ChildItem -Recurse -Filter "*.cpp" | Sort-Object LastWriteTime -Descending | Select-Object -First 1
$commitMsg = "Update solutions $(Get-Date -Format 'yyyy-MM-dd HH:mm')"

if ($recentFile) {
    # Try to extract contest ID from parent folder name
    if ($recentFile.Directory.Name -match "^\d+$") {
        $contestId = $recentFile.Directory.Name
        $commitMsg = "Add solutions for contest $contestId"
    }
}

Write-Host "Committing with message: $commitMsg"

git add .
git commit -m "$commitMsg"
git push

Write-Host "Successfully synced to GitHub!"
