eval('clear all');
eval('clc');
%�����ݼ��ص�������
warning('off');
try
    [filename,filepath]=uigetfile('*.mat','���ļ�');
    load(strcat(filepath,filename));
    fprintf('1.[%s]�Ѽ��ص���������\n',filename);
catch
    clear('filename','filepath');
    return;
end
%��ȡ���صı������жϱ������Ƿ���PSA1_CAN��Sensor_CAN����
Data_Process;