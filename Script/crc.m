function crc = crc(u1,u2,u3,u4,u5,u6,u7,u8)
u = [u1,u2,u3,u4,u5,u6,u7,u8];
crc = 255;
poly = 29;
for i = 1:8
    if(i ~= 8)
        crc = bitxor(crc,u(i));
        for j = 1:8
            if bitand(crc,128)
                crc = bitxor(bitand(crc*2,hex2dec("FF")),poly);
                crc
            else
                crc = bitand(crc*2,hex2dec("FF"));
                crc
            end
        end
    end
end
crc = bitxor(crc,255);
