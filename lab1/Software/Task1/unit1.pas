unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;
  message:string;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
var
  month:string;
begin
  if(datetostr(date)[2] = '/') then
    begin
      message := datetostr(date)[1];
      if(datetostr(date)[4] = '/') then
        month := datetostr(date)[3]
      else
        month := datetostr(date)[3]+ datetostr(date)[4];
    end
  else
    begin
      if(datetostr(date)[1]<>'0') then
        message := datetostr(date)[1] + datetostr(date)[2]
      else
        message := datetostr(date)[2];
      if(datetostr(date)[5] = '/') then
        month := datetostr(date)[4]
      else
        month := datetostr(date)[4]+ datetostr(date)[5];
    end;
    case month of
      '01','1':month := ' січня';
      '02','2':month := ' лютого';
      '03','3':month := ' березня';
      '04','4':month := ' квітня';
      '05','5':month := ' травня';
      '06','6':month := ' червня';
      '07','7':month := ' липня';
      '08','8':month := ' серпня';
      '09','9':month := 'вересня';
      '10':month := ' жовтня';
      '11':month := ' листопада';
      '12':month := ' грудня';
    end;
  message := message + ' ' + month;
  label7.caption := message;
  message := '';
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  randomize;
  case random(3) of
    0:message := inttostr(random(5)+5);
    1:message := inttostr(random(5)+15);
    2:message := inttostr(random(5)+25);
  end;
  label7.Caption := message;
  message:= '';
end;

procedure TForm1.Button3Click(Sender: TObject);
var
  i:integer;
  list:string;
begin
  list := 'АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ''абвгґдеєжзиіїйклмнопрстуфхцчшщьюя';
  if(edit1.Text = '') then
    begin
      showmessage('Введіть слово в поле!');
      exit;
    end;
  for i:= 1 to edit1.GetTextLen do
    if(pos(edit1.Text[i], list)>0) then
      continue
    else
      begin
       Showmessage('Введено недопустимий символ');
       exit;
      end;
  if(pos(edit1.Text, 'Людина, її життя і здоров''я, честь і гідність, недоторканність і безпека визнаються в Україні найвищою соціальною цінністю. Права і свободи людини та їхні гарантії визначають зміст і спрямованість діяльості держави. Держава відповідає перед людиною за свою діяльність. Утвердження і забезпечення прав і свобод людини є головним обов''язком держави.')>0) then
    Label7.caption := 'Текст містить введене слово'
  else
    Label7.caption := 'Текст не містить введеного слова';
end;

end.

