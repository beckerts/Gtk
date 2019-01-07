#include <gtkmm.h>
#include <iostream>

// ok switched from https to ssh. see if it works now

  Gtk::Window* pwindow = nullptr;
  Gtk::Entry* ptxtStatus = nullptr;

  static void on_btnHelloWorld_clicked()
  {
	  if(ptxtStatus) ptxtStatus->set_text("Hello Glade World!");
  }

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  auto refBuilder = Gtk::Builder::create();
  
  try
  {
    refBuilder->add_from_file("basic.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 1;
  }

  refBuilder->get_widget("appWindow",pwindow);
  
  if(pwindow)
  {
	  refBuilder->get_widget("txtStatus", ptxtStatus);
	  
	  Gtk::Button* pButton = nullptr;
	  refBuilder->get_widget("btnHelloWorld", pButton);
	  if(pButton)
	  {
		  pButton->signal_clicked().connect(sigc::ptr_fun(on_btnHelloWorld_clicked));
	  }
  }
  
  app->run(*pwindow);
  
  delete pwindow;
  
  return 0;
}
