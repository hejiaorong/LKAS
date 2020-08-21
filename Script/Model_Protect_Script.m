%% 根据SWC模型自动生成Protect Model和Mat文件
eval('clear all');
eval('clc');
%% 1.根据目录确定slx文件名称并保存版本
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
else
    fprintf('1.您的目标*.slx文件是:[%s]\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %获取slx文件名
module_name = filename(1:4);
warning('off')
ModelSavePath = strcat(path,'\ModelSave');
newfile = strcat(filename,'_AutoSave_',datestr(now,'yyyymmdd_HHMM'));
protectfile = strcat(filename,'_Protect_MIL_',datestr(now,'yyyymmdd_HHMM'));
getNewFileName = strcat(newfile,'.slx');
try
    close_system(filename,newfile);
    movefile(getNewFileName,ModelSavePath); 
    fprintf('1.您已经打开的模型[%s.slx]文件已经另存为[%s.slx]到[%s]\n',filename,newfile,ModelSavePath);
catch
    copyfile(getFileName,ModelSavePath);
    eval(strcat('!rename',32,ModelSavePath,'\',getFileName,32,getNewFileName));
    fprintf('1.您的模型[%s.slx]文件已经另存为[%s.slx]到[%s]\n',filename,newfile,ModelSavePath);
end
open_system(filename);
%% 2.配置Simulink属性，删除Runnable模块
cs = getActiveConfigSet(filename);
set_param(cs,'DefaultUnderspecifiedDataType','single');
set_param(cs,'UseDivisionForNetSlopeComputation','off');
SubSystName = find_system(filename,'SearchDepth',1,'BlockType','SubSystem');
SubSystName = SubSystName{1};
Runnable =get_param(strcat(module_name,'/','Runnable_',module_name,'_Step'),'PortHandles');
Subsystem = get_param(SubSystName,'PortHandles');
delete_line(filename,Runnable.Outport,Subsystem.Trigger);  % 删除相应线段
delete_block(strcat(filename,'/','Runnable_',module_name,'_Step')); % 删除runnable端口
delete_block(strcat(SubSystName,'/function'));
fprintf('2.您的模型[%s.slx]文件已经完成Simulink属性配置并删除Runnable模块\n',filename);
%% 3.输出slxp模型，输出mat文件
getProtectFileName = strcat(protectfile,'.slx');
getProtectFileName1 = strcat(protectfile,'.slxc');
getProtectFileName2 = strcat(protectfile,'.slxp');
getProtectFileName3 = strcat(protectfile,'.mat');
mdlWks = get_param(filename,'ModelWorkspace');
save(mdlWks,getProtectFileName3);
save_system(filename,protectfile);
try
    Rte_Type;
catch
    fprintf('3.！找不到您的“Rte_Type.m”文件，请将文件放于目录下或添加至路径\n');
end
sim(protectfile);
fprintf('3.您已经调整过的[%s.slx]文件已经另存为[%s.slxp]\n',filename,protectfile);
Simulink.ModelReference.protect(protectfile);
%% 4.清理多余文件，规整文件并打包
delete(getProtectFileName);
delete(getProtectFileName1);
delete(strcat(filename,'.slxc'));
close_system(protectfile);
zipfilename = protectfile;
zipfilenames = {getProtectFileName2,getProtectFileName3,'Rte_Type.m'};
zip(zipfilename,zipfilenames);
movefile(strcat(zipfilename,'.zip'),ModelSavePath); 
delete(getProtectFileName2);
delete(getProtectFileName3);
fprintf('您的ProtectMIL模型已经输出至[%s%s]\n',ModelSavePath,strcat('\',zipfilename,'.zip'));
eval('clear all');