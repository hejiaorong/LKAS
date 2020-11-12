eval('clear all');
eval('clc');
close('all');
if questdlg('�˲������ر�����EXCEL��ACCESS������ȷ�ϣ�','����','��','��','��')=='��'
    return;
end
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'EXCEL.EXE',32,'/T'));
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'MSACCESS.EXE',32,'/T'));
%% 1.��ģ�Ͳ���ȡ�궨������
path = cd;
scriptpath = strcat(path,'\Script');
getFileName=ls(strcat(scriptpath,'\*.slx')); %  *�ű���slx����ͬһ���ļ��и��ļ���������ֻ��һ��slx�ļ�
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
    fprintf('1.����Ŀ��*.slx�ļ���:��%s��\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %��ȡslx�ļ���
warning('off');
load_system(filename);
load_system(strcat(filename,'/Clb'));
Clb = find_system(strcat(filename,'/LLClb'),'SearchDepth',2,'BlockType','From');
ClbNum = size(Clb);
dist = Clb{1};
%% 2.���ݱ궨�����ù���궨���ݱ�
path = cd;
clbxlspath = strcat(cd,'\Tools\CANMaster');
fprintf('2.ȷ��Ŀ���ļ���Ŀ¼���С�CAN_Calibration.xls���ļ���ͬʱ���ļ�δ����\n');
clbxlsFileName=strcat(clbxlspath,'\CAN_Calibration.xls'); %  *�ű���excel�����ļ�����ͬһ���ļ��и��ļ���������ֻ��һ���ļ�xlsx�ļ�
opts = spreadsheetImportOptions("NumVariables", 5);
opts.Sheet = 1; %excel �ڼ�ҳ����
opts.DataRange = "A1:E1"; 
opts.VariableNames = ["type","name","value","comment","sort"];
opts.VariableTypes = ["string", "string", "string", "string", "string"];
opts = setvaropts(opts, [1,2,3,4,5], "WhitespaceRule", "preserve");
opts = setvaropts(opts, [1,2,3,4,5], "EmptyFieldRule", "auto");
Clbxlstable = readtable(clbxlsFileName, opts, "UseExcel", false);    % ͬһ���ļ������·�� % ��������
clear  opts;    % �����ʱ����

mdlWks = get_param(filename,'ModelWorkspace');

tag = {ClbNum(1)};
text = {ClbNum(1)};
type = {ClbNum(1)};
value = {ClbNum(1)};
clbnum = 0;
num = 1;
for i = 1:100
    if i<= ClbNum(1)
        str = get_param(Clb(i),'GotoTag');
        str = str{1};
        if length(str)>=10
            tag(num) = get_param(Clb(i),'GotoTag');
            text(num) = get_param(Clb(i),'Description');
            set_param(strcat(filename,'/Clb/Clb',num2str(num)),'GotoTag',tag{num},'TagVisibility','global','Description',text{num});
            new_str = regexpi(Clb{i},'/','split');
            type(num) = new_str(3);
            if isempty(text{num})
                text{num} = 'none';
            end
            v = getVariable(mdlWks,tag{num});
            value{num} = num2str(v.Value);
            addclb = cell(1,5);
            addclb =  [type(num),tag(num),value(num),text(num),num2str(num)];
            Clbxlstable = [Clbxlstable;addclb];
            num = num + 1;
            clbnum = clbnum+1;
        end
    else
        set_param(strcat(filename,'/Clb/Clb',num2str(num)),'GotoTag',strcat('empty',num2str(num)),'TagVisibility','global');
        addclb =  [{''},{''},{''},{''},{''}];
        Clbxlstable = [Clbxlstable;addclb];
        num = num + 1;
    end
    if num > 30
        break
    end
end
%% 3.д��궨���ݱ�
xlswrite(strcat(clbxlspath,'\CAN_Calibration.xls'),table2array(Clbxlstable));
fprintf('3.���ı궨��������д���ļ���CAN_Calibration.xls��\n');
save_system(filename);

