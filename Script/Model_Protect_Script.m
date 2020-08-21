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
else
    fprintf('1.����Ŀ��*.slx�ļ���:[%s]\n',getFileName);
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
SubSystName = find_system(filename,'SearchDepth',1,'BlockType','SubSystem');
SubSystName = SubSystName{1};
Runnable =get_param(strcat(module_name,'/','Runnable_',module_name,'_Step'),'PortHandles');
Subsystem = get_param(SubSystName,'PortHandles');
delete_line(filename,Runnable.Outport,Subsystem.Trigger);  % ɾ����Ӧ�߶�
delete_block(strcat(filename,'/','Runnable_',module_name,'_Step')); % ɾ��runnable�˿�
delete_block(strcat(SubSystName,'/function'));
fprintf('2.����ģ��[%s.slx]�ļ��Ѿ����Simulink�������ò�ɾ��Runnableģ��\n',filename);
%% 3.���slxpģ�ͣ����mat�ļ�
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
    fprintf('3.���Ҳ������ġ�Rte_Type.m���ļ����뽫�ļ�����Ŀ¼�»������·��\n');
end
sim(protectfile);
fprintf('3.���Ѿ���������[%s.slx]�ļ��Ѿ����Ϊ[%s.slxp]\n',filename,protectfile);
Simulink.ModelReference.protect(protectfile);
%% 4.��������ļ��������ļ������
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
fprintf('����ProtectMILģ���Ѿ������[%s%s]\n',ModelSavePath,strcat('\',zipfilename,'.zip'));
eval('clear all');