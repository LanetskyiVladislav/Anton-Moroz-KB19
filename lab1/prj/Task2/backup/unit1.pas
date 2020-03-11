unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls, unit2, Math;

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

procedure TForm1.Button1Click(Sender: TObject);
var
  y,z,q:real;
  x:float;
begin
  if(check(edit1.text,edit2.Text,edit3.text)=false) then
    exit;
  x:=strtofloat(edit1.Text);
  y:=strtofloat(edit2.Text);
  z:=strtofloat(edit3.Text);
  q:=abs(sin(abs(y-power(z, x))) + sqrt(x) - sqrt(power(y*z,4)/2 + 2 * pi));
  label9.caption:= 'Q = ' +  floattostrf(q, ffFixed, 10, 3);
end;

end.

