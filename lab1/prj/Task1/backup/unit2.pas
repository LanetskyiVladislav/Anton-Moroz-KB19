unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils,Graphics, Forms, Dialogs;

var
  str,list:string;
  i:byte;
function check(str:string):boolean;
implementation
function check(str:string):=boolean;
begin
  check:=true;
  list := 'АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ''абвгґдеєжзиіїйклмнопрстуфхцчшщьюя';
  if(str = '') then
    begin
      showmessage('Введіть слово в поле!');
      check:=false;
    end;
  for i:= 1 to str.Length do
    if(pos(str[i], list)>0) then
      continue
    else
      begin
       Showmessage('Введено недопустимий символ');
       check:=false;
      end;
end;

end.

