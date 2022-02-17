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
elseif questdlg('您将输出适用MIL仿真的保护模型','执行确认','是','否','是')=='是'
    fprintf('1.您的目标*.slx文件是:[%s]\n',getFileName);
else
    return;
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
set_param(cs,'FixedStep','0.001');    % Solver设置
SubSystName = find_system(filename,'SearchDepth',1,'BlockType','SubSystem');
SubSystName = SubSystName{1};
Runnable =get_param(strcat(module_name,'/','Runnable_',module_name,'_Step'),'PortHandles');
Subsystem = get_param(SubSystName,'PortHandles');
delete_line(filename,Runnable.Outport,Subsystem.Trigger);  % 删除相应线段
delete_block(strcat(filename,'/','Runnable_',module_name,'_Step')); % 删除runnable端口
delete_block(strcat(SubSystName,'/function'));
fprintf('2.您的模型[%s.slx]文件已经完成Simulink属性配置并删除Runnable模块\n',filename);

delete_block(strcat(SubSystName,'/LKASve_g_ob5H_10'));
delete_block(strcat(SubSystName,'/LKASve_g_ob5L_10'));
delete_block(strcat(SubSystName,'/LKASve_g_ob6H_10'));
delete_block(strcat(SubSystName,'/LKASve_g_ob6L_10'));
delete_block(strcat(SubSystName,'/LKASve_g_ob07H_100'));
delete_block(strcat(SubSystName,'/LKASve_g_ob07L_100'));
delete_block(strcat(SubSystName,'/LKASve_g_ob08H_100'));
delete_block(strcat(SubSystName,'/LKASve_g_ob08L_100'));
delete_block(strcat(SubSystName,'/Monitor'));
delete_block(strcat(filename,'/LKASve_g_ob5H_10'));
delete_block(strcat(filename,'/LKASve_g_ob5L_10'));
delete_block(strcat(filename,'/LKASve_g_ob6H_10'));
delete_block(strcat(filename,'/LKASve_g_ob6L_10'));
delete_block(strcat(filename,'/LKASve_g_ob07H_100'));
delete_block(strcat(filename,'/LKASve_g_ob07L_100'));
delete_block(strcat(filename,'/LKASve_g_ob08H_100'));
delete_block(strcat(filename,'/LKASve_g_ob08L_100'));


%% 3.输出slxp模型，输出mat文件
getProtectFileName = strcat(protectfile,'.slx');
getProtectFileName1 = strcat(protectfile,'.slxc');
getProtectFileName2 = strcat(protectfile,'.slxp');
getProtectFileName3 = strcat(protectfile,'.mat');
mdlWks = get_param(filename,'ModelWorkspace');

ob_LKA_Disable_Reason = Simulink.Signal;
ob_LKA_Disable_Reason.CoderInfo.StorageClass = 'Auto';
ob_LKA_Disable_Reason.Description = '';
ob_LKA_Disable_Reason.DataType = 'single';
ob_LKA_Disable_Reason.Min = [];
ob_LKA_Disable_Reason.Max = [];
ob_LKA_Disable_Reason.DocUnits = '';
ob_LKA_Disable_Reason.Dimensions = -1;
ob_LKA_Disable_Reason.DimensionsMode = 'auto';
ob_LKA_Disable_Reason.Complexity = 'auto';
ob_LKA_Disable_Reason.SampleTime = -1;
ob_LKA_Disable_Reason.InitialValue = '';

ob_LKA_LKADeactvCSyn = Simulink.Signal;
ob_LKA_LKADeactvCSyn.CoderInfo.StorageClass = 'Auto';
ob_LKA_LKADeactvCSyn.Description = '';
ob_LKA_LKADeactvCSyn.DataType = 'single';
ob_LKA_LKADeactvCSyn.Min = [];
ob_LKA_LKADeactvCSyn.Max = [];
ob_LKA_LKADeactvCSyn.DocUnits = '';
ob_LKA_LKADeactvCSyn.Dimensions = -1;
ob_LKA_LKADeactvCSyn.DimensionsMode = 'auto';
ob_LKA_LKADeactvCSyn.Complexity = 'auto';
ob_LKA_LKADeactvCSyn.SampleTime = -1;
ob_LKA_LKADeactvCSyn.InitialValue = '';

ob_LKA_Version = Simulink.Signal;
ob_LKA_Version.CoderInfo.StorageClass = 'Auto';
ob_LKA_Version.Description = '';
ob_LKA_Version.DataType = 'single';
ob_LKA_Version.Min = [];
ob_LKA_Version.Max = [];
ob_LKA_Version.DocUnits = '';
ob_LKA_Version.Dimensions = -1;
ob_LKA_Version.DimensionsMode = 'auto';
ob_LKA_Version.Complexity = 'auto';
ob_LKA_Version.SampleTime = -1;
ob_LKA_Version.InitialValue = '';

LKA_SampleTime = Simulink.Parameter;
LKA_SampleTime.Value = 0.001;
LKA_SampleTime.CoderInfo.StorageClass = 'Custom';
LKA_SampleTime.CoderInfo.Alias = '';
LKA_SampleTime.CoderInfo.Alignment = -1;
LKA_SampleTime.CoderInfo.CustomStorageClass = 'Const';
LKA_SampleTime.CoderInfo.CustomAttributes.HeaderFile = '';
LKA_SampleTime.CoderInfo.CustomAttributes.DefinitionFile = ...
  'LKAS_calib.c';
LKA_SampleTime.CoderInfo.CustomAttributes.Owner = '';
LKA_SampleTime.Description = '';
LKA_SampleTime.DataType = 'single';
LKA_SampleTime.Min = [];
LKA_SampleTime.Max = [];
LKA_SampleTime.DocUnits = '';

LL_CompHdAg_C = Simulink.Parameter;
LL_CompHdAg_C.Value = 0;
LL_CompHdAg_C.CoderInfo.StorageClass = 'Custom';
LL_CompHdAg_C.CoderInfo.Alias = '';
LL_CompHdAg_C.CoderInfo.Alignment = -1;
LL_CompHdAg_C.CoderInfo.CustomStorageClass = 'Const';
LL_CompHdAg_C.CoderInfo.CustomAttributes.HeaderFile = '';
LL_CompHdAg_C.CoderInfo.CustomAttributes.DefinitionFile = ...
  'LKAS_calib.c';
LL_CompHdAg_C.CoderInfo.CustomAttributes.Owner = '';
LL_CompHdAg_C.Description = '';
LL_CompHdAg_C.DataType = 'single';
LL_CompHdAg_C.Min = [];
LL_CompHdAg_C.Max = [];
LL_CompHdAg_C.DocUnits = '';

assignin(mdlWks, 'ob_LKA_Disable_Reason', ob_LKA_Disable_Reason);
assignin(mdlWks, 'ob_LKA_LKADeactvCSyn', ob_LKA_LKADeactvCSyn);
assignin(mdlWks, 'ob_LKA_Version', ob_LKA_Version);
assignin(mdlWks, 'LKA_SampleTime', LKA_SampleTime);
assignin(mdlWks, 'LL_CompHdAg_C', LL_CompHdAg_C);

load_system(filename);
save(mdlWks,getProtectFileName3);
save_system(filename,protectfile);
try
    Rte_Type;
catch
    fprintf('3.！找不到您的“Rte_Type.m”文件，请将文件放于目录下或添加至路径\n');
end
sim(protectfile);
set_param(protectfile,'ModelReferenceNumInstancesAllowed', 'single')
save_system(protectfile);
fprintf('3.您已经调整过的[%s.slx]文件已经另存为[%s.slxp]\n',filename,protectfile);
Simulink.ModelReference.protect(protectfile);
%% 4.清理多余文件，规整文件并打包
delete(getProtectFileName1);
delete(strcat(filename,'.slxc'));
close_system(protectfile);
zipfilename = protectfile;
zipfilenames = {getProtectFileName2,getProtectFileName3,'Rte_Type.m'};
zip(zipfilename,zipfilenames);
movefile(strcat(zipfilename,'.zip'),ModelSavePath); 
delete(getProtectFileName2);
delete(getProtectFileName3);
proj = simulinkproject;
addFile(proj,strcat(ModelSavePath,'\',zipfilename,'.zip'));
addFile(proj,strcat(ModelSavePath,'\',newfile,'.slx'));
delete(getProtectFileName);
fprintf('您的ProtectMIL模型已经输出至[%s%s]\n',ModelSavePath,strcat('\',zipfilename,'.zip'));
eval('clear all');