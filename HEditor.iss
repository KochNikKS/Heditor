; Скрипт создан: Мастер скриптов Inno Setup.
; СМОТРИТЕ ДОКУМЕНТАЦИЮ ДЛЯ ДЕТАЛИЗИРОВАННОГО СОЗДАНИЯ СКРИПТОВ INNO SETUP!

[Setup]
AppName=HTML Editor
AppVerName=HEDitor 1.0
AppPublisher=Konstantin & ko
DefaultDirName={pf}\HEditor
DefaultGroupName=HTML Editor
AllowNoIcons=yes
AlwaysCreateUninstallIcon=yes
LicenseFile=C:\User\Konst\projects\HEditor\Соглашение.txt
; uncomment the following line if you want your installation to run on NT 3.51 too.
; MinVersion=4,3.51

[Tasks]
Name: "desktopicon"; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"; MinVersion: 4,4
Name: "quicklaunchicon"; Description: "Create a &Quick Launch icon"; GroupDescription: "Additional icons:"; MinVersion: 4,4; Flags: unchecked

[Files]
Source: "C:\User\Konst\projects\HEditor\HEditor.exe"; DestDir: "{app}"; CopyMode: alwaysoverwrite
Source: "C:\User\Konst\projects\HEditor\HEditor.ico"; DestDir: "{app}"; CopyMode: alwaysoverwrite
Source: "C:\User\Konst\projects\HEditor\Insertions.dat"; DestDir: "{app}"; CopyMode: alwaysoverwrite

[Icons]
Name: "{group}\HTML Editor"; Filename: "{app}\HEditor.exe"
Name: "{userdesktop}\HTML Editor"; Filename: "{app}\HEditor.exe"; MinVersion: 4,4; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\HTML Editor"; Filename: "{app}\HEditor.exe"; MinVersion: 4,4; Tasks: quicklaunchicon

[Run]
Filename: "{app}\HEditor.exe"; Description: "Launch HTML Editor"; Flags: nowait postinstall skipifsilent

