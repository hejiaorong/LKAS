function [gbkcheckflg,gbkcheckinfo] = Build_GBKCheck()
path = cd;
codefile = strcat(path,'\bin\LKAS_autosar_rtw\LKAS_component.arxml');
fpn = fopen(codefile, 'rt');           %���ĵ�  
i = 1;
cmout = false;
gbklog = {'line','index','line'};
while feof(fpn) ~= 1                %�����ж��ļ�ָ��p������ָ���ļ��е�λ�ã�������ļ�ĩ����������1�����򷵻�0  
    line = fgetl(fpn);            %��ȡ�ĵ���һ��
    if line == -1
       break;
    end
    if contains(line,"<!--") 
        cmout = true;
    end
    if cmout~=1
        idx = int32(line)<=40869&int32(line)>=19968;
        count = sum(idx,'all');
        if count
           gbklog = cat(1,gbklog,{i,count,line});
        end
    end
    if contains(line,"-->")
    cmout = false;
    end
    i = i+1;
end  
fclose(fpn); 
[gbknum,~] = size(gbklog);
if gbknum>1
    gbkcheckflg = true;
    gbkcheckinfo = gbklog;
    disp(gbkcheckinfo);
else
    gbkcheckflg = false;
    gbkcheckinfo = {};
end