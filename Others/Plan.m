for j = 1 : 10
    c1 = 0.005*j;
    v = 60/3.6;
    L = 2.7;
    ttlc = max(min(min(max(0.3,c1*v*1.5),0.6)/(v*c1),2),0.6);
    i = 14.3;
    k = 0.09/v/3.6;
    delta0 = 0  /180*pi;
    kmax = -60  /180*pi;
    k1 = 2*((-c1*(1+k*v*v)*i*L)/v - ttlc*delta0)/ttlc/ttlc;
    if k1<kmax
        k1 = kmax;
        ttlc = max((-delta0+sqrt(delta0*delta0-2*k1*c1))/kmax,(-delta0-sqrt(delta0*delta0-2*k1*c1))/kmax);
        fprintf('kmax')
    end
    fprintf('vy = %4.2f,  ttlc = %4.2f,  k1 = %4.2f,  delta1 = %4.2f\n', c1*v, ttlc, k1, (k1*ttlc+delta0)*180/pi);
    time = 0:0.01:double(int16(ttlc/0.01))*0.01;
    dvt = 0:0.01:double(int16(ttlc/0.01))*0.01; 
    swa = 0:0.01:double(int16(ttlc/0.01))*0.01; 
    delta = 0:0.01:double(int16(ttlc/0.01))*0.01; 
    for m = 1:int16(ttlc/0.01+1+0.00001)
        dvt(m)=(c1*time(m)+v/L/(1+k*v*v)/i*(delta0*time(m)*time(m)/2+1/6*k1*time(m)*time(m)*time(m)))*v;
    end
    
    for m = 1:int16(ttlc/0.01+1+0.00001)
        delta(m)=c1+v/L/(1+k*v*v)/i*(delta0*time(m)+1/2*k1*time(m)*time(m));
    end
    for m = 1:int16(ttlc/0.01+1+0.00001)
        swa(m)=(delta0+k1*time(m))*180/pi;
    end
    subplot(3,1,1);
    plot(time,swa);
    hold on;
    grid on;
    subplot(3,1,2);
    plot(time,delta);
    hold on;
    grid on;
    subplot(3,1,3);
    plot(time,dvt);
    hold on;
    grid on;
    pause(1);
end