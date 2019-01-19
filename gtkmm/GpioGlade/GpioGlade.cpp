#include <gtkmm.h>
#include <iostream>

#include "gpio.hpp"

static GPIO gpio;  


  Gtk::Window* pwindow = nullptr;
  Gtk::Entry* ptxtStatus = nullptr;

  static void on_btnHelloWorld_clicked()
  {
    int pin = 5;
    GPIO::IO io;
    gpio.alt_function(5,io);
    GPIO::alt_name(io);
    int value = gpio.read(pin);
	  if(ptxtStatus) ptxtStatus->set_text("Pin: " + std::to_string(pin) + " alt name: " + GPIO::alt_name(io) + " value: " + std::to_string(value));
  }

  static void on_btnQuit_clicked()
  {
    if(pwindow)
      pwindow->hide();
  }


int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  auto refBuilder = Gtk::Builder::create();
  
  try
  {
    refBuilder->add_from_file("GpioGlade.glade");
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

    Gtk::Button* pbtnQuit = nullptr;
    refBuilder->get_widget("btnQuit", pbtnQuit);
    if(pbtnQuit)
    {
      pbtnQuit->signal_clicked().connect(sigc::ptr_fun(on_btnQuit_clicked));
    }
  }
  
  app->run(*pwindow);
  
  delete pwindow;
  
  return 0;
}
