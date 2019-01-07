# Gtk
Repository for storing Gtk and gtkmm test examples<p>
Nothing special here. Just a personal repository for storing code I created reading the Gtk and gtkmm tutorials.<br>
Goal was to write c++ apps on raspbian to control GPIOs. Experimented writing c++ apps with gtkmm and glade.<p>
Key websites are:<br>
gtkmm: https://developer.gnome.org/gtkmm-tutorial/stable/index.html.en<br>
example code from gtkmm book: https://gitlab.gnome.org/GNOME/gtkmm-documentation/tree/gtkmm-3-24/examples/book<p>
Exploring raspberry pi 2 with cpp code:<br>
Apress points here: https://github.com/Apress/exploring-raspberry-pi-2-w-cpp/tree/master/raspberry_pi2/jessie<br>
Book points here: https://github.com/ve3wwg/raspberry_pi2 Above site appears to be latest. Put this here just in case.<br>
The Makefile in piweb does not work. The following line under piweb needs to be edited:<p>
$(CXX) $(OBJS) -o piweb $(LDFLAGS)<p>
Should read:<p>
$(CXX) $(OBJS) -o piweb -L$(TOPDIR)/lib $(LDFLAGS)<p>
You will get an error about not finding -lrpi2 without the change.<p>
