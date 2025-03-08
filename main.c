#include <gtk/gtk.h>


int main(int argc, char **argv)
{
    //initialisation de gtk
    gtk_init(&argc,& argv);

    GtkWidget *window;
    GtkWidget *entre1;
    GtkWidget *entre2;
    GtkWidget *op_add;
    GtkWidget *op_div;
    GtkWidget *result;
    GtkWidget *button_quit;
    GtkWidget *vbox;
    GtkWidget *hbox1;
    GtkWidget *hbox2;

    //Déclaration des widgets
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    entre1 = gtk_entry_new();
    entre2 = gtk_entry_new();
    op_add = gtk_button_new_with_label("  +  ");
    op_div = gtk_button_new_with_label("  /  ");
    result = gtk_button_new_with_label("  =  ");
    button_quit = gtk_button_new_with_label("Quitter");
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,4);
    hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,2);
    hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,2);

    //Différentes propriétés des widgets
    gtk_window_set_title(GTK_WINDOW(window),"Calculatrice");
    gtk_container_add(GTK_CONTAINER(window),vbox);

    gtk_box_pack_start(GTK_BOX(vbox),hbox1,FALSE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(vbox),hbox2,FALSE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(vbox),result,FALSE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(vbox),button_quit,FALSE,FALSE,10);

    gtk_box_pack_start(GTK_BOX(hbox1),entre1,FALSE,FALSE,10);   
    gtk_box_pack_start(GTK_BOX(hbox1),entre2,FALSE,FALSE,10);

    gtk_box_pack_start(GTK_BOX(hbox2),op_add,FALSE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(hbox2),op_div,FALSE,FALSE,10);


    //Affichage des widgets
    gtk_widget_show_all(window);
    
    //Maintient de la fenêtre
    gtk_main();

    return 0;
}