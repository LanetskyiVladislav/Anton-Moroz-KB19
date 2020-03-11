unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils,Dialogs;
function check(str1,str2,str3:string):boolean;
implementation
function check(str1,str2,str3:string):boolean;
var
  list:string;
  x:byte;
begin
  list:='0123456789,';
  check := true;
  if((str1 = '') or (str2 = '') or (str3 = '')) then
    begin
      showmessage('Введіть усі значення!');
      check := false;
    end;
  for x:=1 to str1.length do
    begin
      if((str1[x]='-')) then
        check := false;
      if(str1[1]=',') then
        check := false;
      if((str1[x]=',') and (pos(',', str1)<>x)) then
        check := false;
      if(pos(str1[x], list)>0) then
        continue
      else
        check := false;
    end;
  for x:= 1 to str2.Length do
    begin
      if((pos(str2[x], list)>0) or(str2[x]=',') or(str2[x]='-')) then

      else
        check := false;
      if(str2[1]=',') then
        check := false;
      if((str2[x]=',') and (pos(',', str2)<>x)) then
        check := false;
      if((str2[1]='-') and (str2[2]=',')) then
        check := false;
      if((x>1) and (str2[x]='-')) then
        check := false;
      if((x=str2.Length) and ((str2[x] = ',') or (str2[x]='-'))) then
        check := false;
    end;

  for x:= 1 to str3.length do
    begin
      if((pos(str3[x], list)>0) or(str3[x]=',') or (str3[x]='-')) then

      else
        check := false;
      if(str3[1]=',') then
        check := false;
      if((str3[x]=',') and (pos(',', str3)<>x)) then
        check := false;
      if((str3[1]='-') and (str3[2]=',')) then
        check := false;
      if((x>1) and (str3[x]='-')) then
        check := false;
      if((x=str3.Length) and ((str3[x] = ',') or (str3[x]='-'))) then
        check := false;
    end;
  if(check = false) then
    begin
      showmessage('Ви ввели недопустиме значення!');
      exit;
    end;
  if(strtofloat(str1)<0) then
    begin
      showmessage('Х не може прийняти дане значення!');
      check := false;
    end;
  if((strtofloat(str1)>100) or (strtofloat(str2)>100) or (strtofloat(str3)>100)) then
    begin
      showmessage('Введено завелике значення для змінної! Максимальне значення = 100.');
       check := false;
    end;
end;

end.

