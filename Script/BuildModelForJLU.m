%% �Զ���������2018B��JLU�������ĳ���
eval('clear all');
eval('clc');
%% 1.���ģ�͵�ModelSave�ļ���
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
warning('off');
ModelSavePath = strcat(path,'\ModelSave');
binPath = strcat(path,'\bin');
cachePath = strcat(path,'\cache');
ScriptPath = strcat(path,'\Script');
date1 = datestr(now,'yyyymmdd_HHMM');
date2 = datestr(now,'yyyy-mm-dd-HH-MM');
newSWCfile = strcat(filename,'_AutoSave_',date1);
getNewSWCName = strcat(newSWCfile,'.slx');
JLUName = strcat('D53_',module_name);
getJLUfile = strcat(JLUName,'.slx');
newJLUfile = strcat(JLUName,'_JLU_',date1);
getNewJLUName = strcat(newJLUfile,'.slx');
try
    close_system(getFileName,newSWCfile);
    movefile(getFileName,ModelSavePath);
    fprintf('1.���Ѿ��򿪵�ģ��[%s]�ļ��Ѿ����Ϊ[%s.slx]��[%s]\n',getFileName,newSWCfile,ModelSavePath);
catch
    copyfile(getFileName,ModelSavePath);
    eval(strcat('!rename',32,ModelSavePath,'\',getFileName,32,getNewSWCName));
    fprintf('1.����ģ��[%s]�ļ��Ѿ����Ϊ[%s.slx]��[%s]\n',getFileName,newSWCfile,ModelSavePath);
end
try
    close_system(JLUName,newJLUfile);
    movefile(getNewJLUName,ModelSavePath);
    fprintf('1.���Ѿ��򿪵�ģ��[%s]�ļ��Ѿ����Ϊ[%s]��[%s]\n',getJLUfile,getNewJLUName,ModelSavePath);
catch
    copyfile(strcat(ScriptPath,'\',getJLUfile),ModelSavePath);
    eval(strcat('!rename',32,ModelSavePath,'\',getJLUfile,32,getNewJLUName));
    fprintf('1.����ģ��[%s]�ļ��Ѿ����Ϊ[%s]��[%s]\n',getJLUfile,getNewJLUName,ModelSavePath);
end
warning('off');
open_system(newSWCfile);
open_system(newJLUfile);
%% 2.Ǩ��ModelWorkspace�����궨�۲�������
matname = 'myVars';
newmatname = 'new_myVars';
mdlWks = get_param(newSWCfile,'ModelWorkspace');
mdlWks.DataSource = 'MATLAB File';
mdlWks.FileName = strcat(matname,'.m');
saveToSource(mdlWks);
fid=fopen(strcat(newmatname,'.m'),'wt');      %�½�һ��txt�ļ�  
phns = strcat(matname,'.m');                 %Ҫ��ȡ���ĵ����ڵ�·��  
fpn = fopen (phns, 'rt');           %���ĵ�  
while feof(fpn) ~= 1                %�����ж��ļ�ָ��p������ָ���ļ��е�λ�ã�������ļ�ĩ����������1�����򷵻�0  
    file = fgetl(fpn);            %��ȡ�ĵ���һ��   
    if file == -1
        break;
    end
    if contains(file,"StorageClass = 'Custom'")
        new_str = strrep(file,"StorageClass = 'Custom'","StorageClass = 'Auto'");
        fprintf(fid,'%s\n',new_str);%�µ��ַ���д�뵱�½���txt�ĵ���
    else
        new_str = strrep(file,strcat(module_name,'_calib.c'),' ');
        fprintf(fid,'%s\n',new_str);%�µ��ַ���д�뵱�½���txt�ĵ���  
    end
end  
fclose(fid); 
mdlWks = get_param(newJLUfile,'ModelWorkspace');
clear(mdlWks);
mdlWks.DataSource = 'MATLAB File';
mdlWks.FileName = strcat(newmatname,'.m');
reload(mdlWks);
mdlWks.DataSource = 'Model File';
fclose('all');
fprintf('2.����ģ���Ѿ���ɱ궨���͹۲�����������\n');
%% 3.Ǩ��ģ�鲢����
SubSystName = find_system(newSWCfile,'SearchDepth',1,'BlockType','SubSystem');
SubSystName = SubSystName{1};
delete_line(newJLUfile,'LLClb/1','bsLLClb/1');
delete_line(newJLUfile,'bsInInfo1/1','LL/1'); 
delete_line(newJLUfile,'bsLLClb1/1','LL/2'); 
delete_line(newJLUfile,'LL/1','LLOut/1'); 
delete_block(strcat(newJLUfile,'/','LLClb'));
delete_block(strcat(newJLUfile,'/','LL'));
add_block(strcat(newSWCfile,'/',module_name,'/','LL'),strcat(newJLUfile,'/LL'),'Position',[700 400 950 650]);
add_block(strcat(newSWCfile,'/',module_name,'/','LLClb'),strcat(newJLUfile,'/LLClb'),'Position',[100 415 350 515]);
add_line(newJLUfile,'LLClb/1','bsLLClb/1');
add_line(newJLUfile,'bsInInfo1/1','LL/1'); 
add_line(newJLUfile,'bsLLClb1/1','LL/2'); 
add_line(newJLUfile,'LL/1','LLOut/1'); 
Annotation = find_system(newJLUfile,'FindAll','on','SearchDepth',1,'Type','annotation');
set_param(Annotation(1),'Name',date2)
fprintf('3.����ģ���Ѿ����Ǩ����%s\n',getNewJLUName);
%% 4.���в�����ģ��
cd(ModelSavePath);
try
    sim(newJLUfile);
    try
        slbuild(newJLUfile,'StandaloneRTWTarget','ForceTopModelBuild',true)
        fprintf('3.����ģ������ɱ��벢���ɴ���\n')
    catch error
        if error.identifier == "RTW:makertw:makeHookError"
        	fprintf('3.δ��⵽�Ϸ��ļ��ܹ�����������ԣ�\n')
        else
            fprintf('3.����ģ���޷��������룬����\n')
        end
        delete(strcat(matname,'.m'));
        delete(strcat(newmatname,'.m'));
        delete(strcat(newJLUfile,'.slxc'));
        return;
    end
catch
    fprintf('3.����ģ���޷��������У�����ģ��\n')
    delete(strcat(matname,'.m'));
    delete(strcat(newmatname,'.m'));
    delete(strcat(newJLUfile,'.slxc'));
    return;
end

%% 5.�رղ�������ģ�ͣ�ɾ�������ļ�
close_system(newJLUfile,1);
close_system(newSWCfile,0);
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'ide.exe',32,'/T'));
delete(strcat(cachePath,'\',newJLUfile,'.slxc'));
try
    rmdir(strcat(cachePath,'\slprj'),'s');
catch
end
copyfile(strcat(binPath,'\',newJLUfile,'_MPC5675Krt\bin\internal_FLASH.mot'),ModelSavePath);
eval(strcat('!rename',32,ModelSavePath,'\','internal_FLASH.mot',32,strcat(newJLUfile,'.mot')));
try
    rmdir(strcat(binPath,'\',newJLUfile,'_MPC5675Krt'),'s');
catch
end
cd(path);
delete(strcat(matname,'.m'));
delete(strcat(newmatname,'.m'));
proj = simulinkproject;
addFile(proj,strcat(ModelSavePath,'\',getNewJLUName));
addFile(proj,strcat(ModelSavePath,'\',getNewSWCName));
addFile(proj,strcat(ModelSavePath,'\',newJLUfile,'.mot'));
eval('clear all');