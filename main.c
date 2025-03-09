#include <gtk/gtk.h>
#include <stdlib.h>

void addition(GtkWidget * widget,gpointer * data);
void division(GtkWidget * widget,gpointer * data);


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
    result = gtk_label_new("Résultat = ");
    button_quit = gtk_button_new_with_label("Quitter");
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,4);
    hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,2);
    hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,2);

    //Différentes propriétés des widgets
    gtk_window_set_title(GTK_WINDOW(window),"Calculatrice");
    gtk_container_add(GTK_CONTAINER(window),vbox);

    gtk_box_pack_start(GTK_BOX(vbox),hbox1,FALSE,TRUE,10);
    gtk_box_pack_start(GTK_BOX(vbox),hbox2,FALSE,TRUE,10);
    
    gtk_box_pack_start(GTK_BOX(hbox1),entre1,TRUE,TRUE,10);   
    gtk_box_pack_start(GTK_BOX(hbox1),entre2,TRUE,TRUE,10);
    
    gtk_box_pack_start(GTK_BOX(hbox2),op_add,TRUE,TRUE,10);
    gtk_box_pack_start(GTK_BOX(hbox2),op_div,TRUE,TRUE,10);
    
    gtk_box_pack_start(GTK_BOX(vbox),result,TRUE,TRUE,10);
    gtk_box_pack_start(GTK_BOX(vbox),button_quit,FALSE,FALSE,10);

    //Declaration d'un tableau de widget pour les fonctions
    GtkWidget *donnees[3] = {entre1,entre2,result};

    //Affichage des widgets
    gtk_widget_show_all(window);
    
    //Fermeture du programme
    g_signal_connect(G_OBJECT(button_quit),"clicked",G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

    // Connexion des signaux des boutons effectuant les opérations
    g_signal_connect(op_add,"clicked",G_CALLBACK(addition),donnees);
    g_signal_connect(op_div,"clicked",G_CALLBACK(division),donnees);

    //Maintient de la fenêtre
    gtk_main();      

    return 0;
}

void addition(GtkWidget * widget,gpointer * data)
{
    GtkWidget **widgets = (GtkWidget **)data;
    GtkEntry *entre1    = GTK_ENTRY(widgets[0]);   
    GtkEntry *entre2 = GTK_ENTRY(widgets[1]);
    GtkLabel *result = GTK_LABEL(widgets[2]);
    
    const gchar *input1 = gtk_entry_get_text(entre1);
    const gchar *input2 = gtk_entry_get_text(entre2);

    float a=0.0, b=0.0;
    a = atof(input1);
    b = atof(input2);

    gchar resultat[60];
    g_snprintf(resultat,sizeof(resultat),"%2.3f",a+b);
    gtk_label_set_text(result,resultat);

}
void division(GtkWidget * widget,gpointer * data)
{
    GtkWidget **widgets = (GtkWidget **)data;
    GtkEntry *input1 = GTK_ENTRY(widgets[0]);
    GtkEntry *input2 = GTK_ENTRY(widgets[1]);
    GtkLabel *result = GTK_LABEL(widgets[2]);

    const gchar *text1 = gtk_entry_get_text(input1);
    const gchar *text2 = gtk_entry_get_text(input2);

    float a=0.0, b=0.0;
    
    a = atof(text1);
    b = atof(text2);

    gchar resultat[20];
    g_snprintf(resultat,sizeof(resultat),"%2.3f",a/b);
    gtk_label_set_text(result,resultat);

}