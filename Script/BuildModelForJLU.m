%% 自动编译适用2018B版JLU工具链的程序
eval('clear all');
eval('clc');
%% 1.另存模型到ModelSave文件夹
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
    fprintf('1.您已经打开的模型[%s]文件已经另存为[%s.slx]到[%s]\n',getFileName,newSWCfile,ModelSavePath);
catch
    copyfile(getFileName,ModelSavePath);
    eval(strcat('!rename',32,ModelSavePath,'\',getFileName,32,getNewSWCName));
    fprintf('1.您的模型[%s]文件已经另存为[%s.slx]到[%s]\n',getFileName,newSWCfile,ModelSavePath);
end
try
    close_system(JLUName,newJLUfile);
    movefile(getNewJLUName,ModelSavePath);
    fprintf('1.您已经打开的模型[%s]文件已经另存为[%s]到[%s]\n',getJLUfile,getNewJLUName,ModelSavePath);
catch
    copyfile(strcat(ScriptPath,'\',getJLUfile),ModelSavePath);
    eval(strcat('!rename',32,ModelSavePath,'\',getJLUfile,32,getNewJLUName));
    fprintf('1.您的模型[%s]文件已经另存为[%s]到[%s]\n',getJLUfile,getNewJLUName,ModelSavePath);
end
warning('off');
open_system(newSWCfile);
open_system(newJLUfile);
%% 2.迁移ModelWorkspace调整标定观测量配置
matname = 'myVars';
newmatname = 'new_myVars';
mdlWks = get_param(newSWCfile,'ModelWorkspace');
mdlWks.DataSource = 'MATLAB File';
mdlWks.FileName = strcat(matname,'.m');
saveToSource(mdlWks);
fid=fopen(strcat(newmatname,'.m'),'wt');      %新建一个txt文件  
phns = strcat(matname,'.m');                 %要读取的文档所在的路径  
fpn = fopen (phns, 'rt');           %打开文档  
while feof(fpn) ~= 1                %用于判断文件指针p在其所指的文件中的位置，如果到文件末，函数返回1，否则返回0  
    file = fgetl(fpn);            %获取文档第一行   
    if file == -1
        break;
    end
    if contains(file,"StorageClass = 'Custom'")
        new_str = strrep(file,"StorageClass = 'Custom'","StorageClass = 'Auto'");
        fprintf(fid,'%s\n',new_str);%新的字符串写入当新建的txt文档中
    else
        new_str = strrep(file,strcat(module_name,'_calib.c'),' ');
        fprintf(fid,'%s\n',new_str);%新的字符串写入当新建的txt文档中  
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
fprintf('2.您的模型已经完成标定量和观测量属性配置\n');
%% 3.迁移模块并连线
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
fprintf('3.您的模型已经完成迁移至%s\n',getNewJLUName);
%% 4.运行并编译模型
cd(ModelSavePath);
try
    sim(newJLUfile);
    try
        slbuild(newJLUfile,'StandaloneRTWTarget','ForceTopModelBuild',true)
        fprintf('3.您的模型已完成编译并生成代码\n')
    catch error
        if error.identifier == "RTW:makertw:makeHookError"
        	fprintf('3.未检测到合法的加密狗，请检查后重试！\n')
        else
            fprintf('3.您的模型无法正常编译，请检查\n')
        end
        delete(strcat(matname,'.m'));
        delete(strcat(newmatname,'.m'));
        delete(strcat(newJLUfile,'.slxc'));
        return;
    end
catch
    fprintf('3.您的模型无法正常运行，请检查模型\n')
    delete(strcat(matname,'.m'));
    delete(strcat(newmatname,'.m'));
    delete(strcat(newJLUfile,'.slxc'));
    return;
end

%% 5.关闭并不保存模型，删除多余文件
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