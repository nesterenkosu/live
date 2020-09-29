# include <gtk/gtk.h>

GtkWidget *window, *button;

void btn_onclick() {
    gtk_button_set_label(GTK_BUTTON(button),"Hello!");
}

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);
    
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    //Sozdanie knopki
    button = gtk_button_new_with_label("Click here");
    
    //Dobavlenie knopki v okno
    gtk_container_add(GTK_CONTAINER(window),button);
    
    gtk_widget_show_all(window);
    
    g_signal_connect_swapped(
	G_OBJECT(window),
	"destroy",
	G_CALLBACK(gtk_main_quit),
	NULL);
    
    g_signal_connect_swapped(
	G_OBJECT(button),
	"clicked",
	G_CALLBACK(btn_onclick),
	NULL
    );
    
    gtk_main();
    return 0;
}