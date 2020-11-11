path = cd;
codefile = strcat(path,'\bin\LKAS_autosar_rtw\LKAS.c');
fpn = fopen(codefile, 'rt');           %���ĵ�  
i = 1;
cmout = false;
while feof(fpn) ~= 1                %�����ж��ļ�ָ��p������ָ���ļ��е�λ�ã�������ļ�ĩ����������1�����򷵻�0  
    line = fgetl(fpn);            %��ȡ�ĵ���һ��   
    if line == -1
        break;
    end
    if contains(line,"/*")
        cmout = true;
    end
    if contains(line,"*/")
        cmout = false;
    end
    if cmout == true
        i = i+1;
        continue
    end
    count = [];
    count = [count,regexp(line,'[Ff]loat64')];
    count = [count,regexp(line,'FLOAT64')];
    count = [count,regexp(line,'[- ][0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]\.[0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]E[0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]\.[0-9]E[0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]E-[0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]\.[0-9]E-[0-9][; ]')];


    if contains(line,"float64")||contains(line,'FLOAT64')&&(i <= MonitorNum)
        new_str = regexpi(line,' ','split');
        new_str(3) = strcat('M',num2str(i+100),'_',tag(i));
        newline = strjoin(new_str,' ');
        i = i + 1;
        fprintf(fid,'%s\n',newline);%�µ��ַ���д�뵱�½��ĵ���
    else
        fprintf(fid,'%s\n',line);%�µ��ַ���д�뵱�½��ĵ���
    end
end  
fclose(fid); 
fclose('all');