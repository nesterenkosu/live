# include <gtk/gtk.h>

GtkWidget *btn_Go, *ent_Name;

void on_btn_Go_clicked(){
    char buf[255];
    sprintf(
            buf,
            "Hello, %s!",
            gtk_entry_get_text(GTK_ENTRY(ent_Name))
    );
    gtk_button_set_label(GTK_BUTTON(btn_Go),buf);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);
    
    //Подгрузка интерфейса пользователя из Glade-Файла
    GtkBuilder *builder=gtk_builder_new();
    GError *error=NULL;
    if(!gtk_builder_add_from_file(builder,"gui.glade",&error)) {
	//Если при загрузке интерфейса произошла ошибка
	//выведем её описание и завершим программу
	g_warning("%s",error->message);
	return 1;
    }
    
    //Получение доступа к объекту окна, объявленному в Glade-файле
    GtkWidget *window;
    window=GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    btn_Go=GTK_WIDGET(gtk_builder_get_object(builder,"btn_Go"));
    ent_Name=GTK_WIDGET(gtk_builder_get_object(builder,"ent_Name"));

    gtk_widget_show(window);
    
    //Podkluchit funkcii v kode k obrabotchikam
    //zadannym v Glade
    gtk_builder_connect_signals(builder,NULL);

    g_signal_connect_swapped(
	G_OBJECT(window),
	"destroy",
	G_CALLBACK(gtk_main_quit),
	NULL);
    
    gtk_main();
    return 0;
}
