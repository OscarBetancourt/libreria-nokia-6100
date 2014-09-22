s=serial('COM4');

ima1=imread('leo.jpg');
rojo2=ima1( :,:,1);
verde2=ima1(:,:,2);
azul2=ima1(:,:,3);

ima=imread('1.jpg');
rojo=ima( :,:,1);
verde=ima(:,:,2);
azul=ima(:,:,3);

ima2=imread('sim.jpg');
rojo1=ima2( :,:,1);
verde1=ima2(:,:,2);
azul1=ima2(:,:,3);

%=['W',0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,'O'];
%env2=[255,255,255,64,127,8];
%set(s,'outputBufferSize',t.bytes);
set(s,'BaudRate',9600);
set(s,'StopBits',2);
set(s,'DataBits',8);
set(s,'Parity','odd');
set(s,'OutputBufferSize',2); % 
set(s,'Timeout',3);
fopen(s)



for i=1:132
  for c=1:132
      fwrite(s,rojo2(i,c),'char')
      fwrite(s,verde2(i,c),'char')
      fwrite(s,azul2(i,c),'char')

  end
end 

for i=1:132
  for c=1:132
      fwrite(s,rojo(i,c),'char')
      fwrite(s,verde(i,c),'char')
      fwrite(s,azul(i,c),'char')
        % set(s,'Timeout',5); 

  end
end 

for i=1:132
  for c=1:132
      fwrite(s,rojo1(i,c),'char')
      fwrite(s,verde1(i,c),'char')
      fwrite(s,azul1(i,c),'char')
        % set(s,'Timeout',5); 

  end
end 
%fwrite(s,'0','char')

%for i=1:27
%fwrite(s,env(i),'char')
%end
%for c=1:6
%fwrite(s,env2(c),'char')
%end
fclose(s)
delete(s)
clear s;