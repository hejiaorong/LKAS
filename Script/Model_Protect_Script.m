%% ����SWCģ���Զ�����Protect Model��Mat�ļ�
eval('clear all');
eval('clc');
%% 1.����Ŀ¼ȷ��slx�ļ����Ʋ�����汾
path = cd;
getFileName=ls(strcat(pwd,'\*.slx')); %  *�ű���slx����ͬһ���ļ��и��ļ���������ֻ��һ��slx�ļ�
FileNum = size(getFileName);
if  isequal(getFileName,'') % ��ֹѡ����ļ���
    fprintf('��ǰĿ¼��û���ҵ�*.slx�ļ�\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('��ǰĿ¼�´��ڲ�ֹ1��*.slx�ļ�\n');
    eval('clear all');
    return;
elseif questdlg('�����������MIL����ı���ģ��','ִ��ȷ��','��','��','��')=='��'
    fprintf('1.����Ŀ��*.slx�ļ���:[%s]\n',getFileName);
else
    return;
end
filename = getFileName(1:length(getFileName)-4);    %��ȡslx�ļ���
module_name = filename(1:4);
warning('off')
ModelSavePath = strcat(path,'\ModelSave');
newfile = strcat(filename,'_AutoSave_',datestr(now,'yyyymmdd_HHMM'));
protectfile = strcat(filename,'_Protect_MIL_',datestr(now,'yyyymmdd_HHMM'));
getNewFileName = strcat(newfile,'.slx');
try
    close_system(filename,newfile);
    movefile(getNewFileName,ModelSavePath); 
    fprintf('1.���Ѿ��򿪵�ģ��[%s.slx]�ļ��Ѿ����Ϊ[%s.slx]��[%s]\n',filename,newfile,ModelSavePath);
catch
    copyfile(getFileName,ModelSavePath);
    eval(strcat('!rename',32,ModelSavePath,'\',getFileName,32,getNewFileName));
    fprintf('1.����ģ��[%s.slx]�ļ��Ѿ����Ϊ[%s.slx]��[%s]\n',filename,newfile,ModelSavePath);
end
open_system(filename);
%% 2.����Simulink���ԣ�ɾ��Runnableģ��
cs = getActiveConfigSet(filename);
set_param(cs,'DefaultUnderspecifiedDataType','single');
set_param(cs,'UseDivisionForNetSlopeComputation','off');
set_param(cs,'FixedStep','0.001');    % Solver����
SubSystName = find_system(filename,'SearchDepth',1,'BlockType','SubSystem');
SubSystName = SubSystName{1};
Runnable =get_param(strcat(module_name,'/','Runnable_',module_name,'_Step'),'PortHandles');
Subsystem = get_param(SubSystName,'PortHandles');
delete_line(filename,Runnable.Outport,Subsystem.Trigger);  % ɾ����Ӧ�߶�
delete_block(strcat(filename,'/','Runnable_',module_name,'_Step')); % ɾ��runnable�˿�
delete_block(strcat(SubSystName,'/function'));
fprintf('2.����ģ��[%s.slx]�ļ��Ѿ����Simulink�������ò�ɾ��Runnableģ��\n',filename);

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


%% 3.���slxpģ�ͣ����mat�ļ�
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
    fprintf('3.���Ҳ������ġ�Rte_Type.m���ļ����뽫�ļ�����Ŀ¼�»������·��\n');
end
sim(protectfile);
set_param(protectfile,'ModelReferenceNumInstancesAllowed', 'single')
save_system(protectfile);
fprintf('3.���Ѿ���������[%s.slx]�ļ��Ѿ����Ϊ[%s.slxp]\n',filename,protectfile);
Simulink.ModelReference.protect(protectfile);
%% 4.��������ļ��������ļ������
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
fprintf('����ProtectMILģ���Ѿ������[%s%s]\n',ModelSavePath,strcat('\',zipfilename,'.zip'));
eval('clear all');