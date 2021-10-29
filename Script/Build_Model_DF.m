% eval('clear all');
eval('clc');
%% 1.根据目录确定slx文件名称
path = cd;
getFileName=ls(strcat(pwd,'\*.slx')); %  *脚本和slx放在同一个文件夹该文件夹下有且只有一个slx文件
FileNum = size(getFileName);
if  isequal(getFileName,'') % 防止选择空文件夹
    fprintf('当前目录下没有找到*.slx文件\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('当前目录下存在不止1个*.slx文件\n');
    eval('clear all');
    return;
elseif questdlg('您将编译适用于东风控制器的程序，请您保存模型。是否继续？','编译确认','是','否','是')=='是'
    fprintf('1.您的目标*.slx文件是:[%s]\n',getFileName);
else
    return;
end
warning('off');
rmpath('D:\ProgramFiles\MATLAB\toolbox\rtw\targets\asap2\asap2\CANape_user')
ModelSavePath = strcat(path,'\ModelSave');
binPath = strcat(path,'\bin');
filename = getFileName(1:length(getFileName)-4);    %获取slx文件名
slbuild(filename,'StandaloneRTWTarget','ForceTopModelBuild',true)
close_system(filename);
zipfile = strcat(filename,'_',datestr(now,'yyyymmdd'));
ziplist = {strcat(binPath,'\',filename,'_autosar_rtw')};
zip(strcat(zipfile,'.zip'),ziplist);
movefile(strcat(zipfile,'.zip'),ModelSavePath); 
proj = simulinkproject;
addFile(proj,strcat(ModelSavePath,'\',zipfile,'.zip'));
delete(strcat(filename,'.slxc'));
delete(strcat(filename,'_autosar_rtw'));
eval('clear all');
[Fcheckflg,Fcheckinfo] = Build_FloatCheck();
if Fcheckflg
    fprintf(2,'【警告】您生成的代码含有double数据类型，请检查！\n');
    msgbox('您生成的代码含有double数据类型', '警告','error');
    eval('Fcheckinfo');
else
    fprintf('【成功】您生成的代码已打包\n');
    eval('clear all');
end
