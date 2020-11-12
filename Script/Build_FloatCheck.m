function [fcheckflg,fcheckinfo] = Build_FloatCheck()
path = cd;
codefile = strcat(path,'\bin\LKAS_autosar_rtw\LKAS.c');
fpn = fopen(codefile, 'rt');           %���ĵ�  
i = 1;
cmout = false;
doublelog = {'line','index','line'};
while feof(fpn) ~= 1                %�����ж��ļ�ָ��p������ָ���ļ��е�λ�ã�������ļ�ĩ����������1�����򷵻�0  
    line = fgetl(fpn);            %��ȡ�ĵ���һ��   
    if line == -1
        break;
    end
    sprintf(line,i);
    if contains(line,"/*")
        cmout = true;
    end
    if contains(line,"*/")
        cmout = false;
    end
    if cmout
        i = i+1;
        continue
    end
%     if regexp(line,'for (', 'once')
%         i = i+1;
%         continue
%     end
    count = [];
    count = [count,regexp(line,'[Ff]loat64')];
    count = [count,regexp(line,'FLOAT64')];
%    count = [count,regexp(line,'[- ][0-9][; ]')];
    count = [count,regexp(line,'[0-9]\.[0-9][); ]')];
    count = [count,regexp(line,'[0-9]E[0-9][); ]')];
    count = [count,regexp(line,'[0-9]\.[0-9]E[0-9][); ]')];
    count = [count,regexp(line,'[0-9]E-[0-9][); ]')];
    count = [count,regexp(line,'[0-9]\.[0-9]E-[0-9][); ]')];
    if ~isempty(count)
        sprintf(line,i);
        doublelog = cat(1,doublelog,{i,count,line});
    end
    i = i+1;
end  
fclose(fpn); 
[doublenum,~] = size(doublelog);
if doublenum>1
    fcheckflg = true;
    fcheckinfo = doublelog;
else
    fcheckflg = false;
    fcheckinfo = {};
end