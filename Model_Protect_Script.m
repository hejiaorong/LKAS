%% ���ݽӿ��ĵ��Զ�����ģ�ͽű�
eval('clear all');
eval('clc');
%% 1.����Ŀ¼ȷ��slx�ļ����Ʋ�����汾
[path,~]=fileparts(mfilename('fullpath'));
getFileName=ls(strcat(pwd,'\*.slx')); %  *�ű���excel�����ļ�����ͬһ���ļ��и��ļ���������ֻ��һ���ļ�xlsx�ļ�
FileNum = size(getFileName);
if  isequal(getFileName,'') % ��ֹѡ����ļ���
    fprintf('��ǰĿ¼��û���ҵ�*.slx�ļ�\n');
elseif  FileNum ~= 1
    fprintf('��ǰĿ¼�´��ڲ�ֹ1��*.slx�ļ�\n');
else
    fprintf('���Ŀ��*.slx�ļ���:[%s]\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %��ȡslx�ļ���
module_name = filename(1:4);
warning('off')
ModelSavePath = strcat(path,'\ModelSave');
newfile = strcat(filename,'_AutoSave_',datestr(now,'yyyymmdd_HHMM'));
getNewFileName = strcat(newfile,'.slx');
try
    close_system(filename,newfile);
    movefile(getNewFileName,ModelSavePath); 
    fprintf('���Ѿ��򿪵�ģ��[%s.slx]�ļ��Ѿ����Ϊ[%s.slx]��[%s]\n',filename,newfile,ModelSavePath);
catch
    copyfile(getFileName,ModelSavePath);
    eval(strcat('!rename',32,ModelSavePath,'\',getFileName,32,getNewFileName));
    fprintf('����ģ��[%s.slx]�ļ��Ѿ����Ϊ[%s.slx]��[%s]\n',filename,newfile,ModelSavePath);
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
fprintf('����ģ��[%s.slx]�ļ��Ѿ����Simulink�������ò�ɾ��Runnableģ��\n',filename);
protectfile = strcat(filename,'_Protect_',datestr(now,'yyyymmdd_HHMM'));
getProtectFileName = strcat(protectfile,'.slx');
getProtectFileName1 = strcat(protectfile,'.slxc');
getProtectFileName2 = strcat(protectfile,'.slxp');
getProtectFileName3 = strcat(protectfile,'.mat');
mdlWks = get_param(filename,'ModelWorkspace');
save(mdlWks,getProtectFileName3);
fprintf('���Ѿ���������[%s.slx]�ļ�ModelWorkspace�Ѿ����Ϊ[%s.mat]\n',filename,protectfile);
save_system(filename,protectfile);
fprintf('���Ѿ���������[%s.slx]�ļ��Ѿ����Ϊ[%s.slx]\n',filename,protectfile);
sim(protectfile);
Simulink.ModelReference.protect(protectfile);
delete(getProtectFileName);
delete(getProtectFileName1);
movefile(getProtectFileName2,ModelSavePath); 
movefile(getProtectFileName3,ModelSavePath); 
delete(strcat(filename,'.slxc'));
eval('clear all');