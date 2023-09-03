set SOLN_DIR=%~dp0

pushd %SOLN_DIR%

git clone --single-branch --depth=1 --branch=v2.1.3 https://github.com/CoolProp/IF97 IF97

popd

echo. DONE
pause