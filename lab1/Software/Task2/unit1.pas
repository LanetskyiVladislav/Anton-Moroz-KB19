unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Image1: TImage;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    procedure Button1Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

function power(a:real; b:integer):real;
var
  i:integer;
begin
  power:=a;
  if(b>=2) then
    for i:= 2 to b do
      power:=power*a
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  y,z,q:real;
  x:integer;
  list:string;
begin
  list:='0123456789';
  if((edit1.text = '') or (edit2.text = '') or (edit3.text = '')) then
    begin
      showmessage('Введіть усі значення!');
      exit;
    end;


  for x:=1 to edit1.GetTextLen do
    begin
      if((edit1.text[x]=',') or (edit1.text[x]='-')) then
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if(pos(edit1.text[x], list)>0) then
        continue
      else
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
    end;
  for x:= 1 to edit2.gettextlen do
    begin
      if((pos(edit2.text[x], list)>0) or(edit2.text[x]=',') or(edit2.Text[x]='-')) then

      else
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if(edit2.text[1]=',') then
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if((edit2.text[x]=',') and (pos(',', edit2.text)<>x)) then
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if((edit2.text[1]='-') and (edit2.text[2]=',')) then
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if((x>1) and (edit1.Text[x]='-')) then
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if((x=edit2.GetTextLen) and ((edit2.text[x] = ',') or (edit2.text[x]='-'))) then
          begin
            showmessage('Ви ввели недопустиме значення!');
            exit;
          end;
    end;

  for x:= 1 to edit3.gettextlen do
    begin
      if((pos(edit3.text[x], list)>0) or(edit3.text[x]=',') or (edit3.Text[x]='-')) then

      else
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if(edit3.text[1]=',') then
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if((edit3.text[x]=',') and (pos(',', edit3.text)<>x)) then
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if((edit3.text[1]='-') and (edit3.text[2]=',')) then
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if((x>1) and (edit3.Text[x]='-')) then
        begin
          showmessage('Ви ввели недопустиме значення!');
          exit;
        end;
      if((x=edit3.GetTextLen) and ((edit3.text[x] = ',') or (edit3.text[x]='-'))) then
          begin
            showmessage('Ви ввели недопустиме значення!');
            exit;
          end;
    end;

  if(strtoint(edit1.text)<0) then
    begin
      showmessage('Х не може прийняти дане значення!');
      exit;
    end;
  x:=strtoint(edit1.Text);
  y:=strtofloat(edit2.Text);
  z:=strtofloat(edit3.Text);
  q:=abs(sin(abs(y-power(z, x))) + sqrt(x) - sqrt(power(y*z,4)/2 + 2 * pi));
  label9.caption:= 'Q = ' +  floattostr(q);
end;


end.

