#include "prog.h"

Prog::Prog(QWidget *parent):QMainWindow(parent)
{	
	btn=new QPushButton("Click here",this);
	btn->setGeometry(1,1,100,100);
	
	connect(btn,SIGNAL(clicked()),this,SLOT(btn_click()));
}

void Prog::btn_click() {
    btn->setText("Hello!");
}

