using System;
using Gtk;

public partial class MainWindow : Gtk.Window
{
	public MainWindow () : base(Gtk.WindowType.Toplevel)
	{
		Build ();
	}

	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}
	protected virtual void OnBtnGoClicked (object sender, System.EventArgs e)
	{
		btn_Go.Label="Hello,"+ent_Name.Text+"!";
	}
	
	
}

