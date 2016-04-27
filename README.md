# reloaduwsgi

This is a very very simple application
that allows a single user to reload
a service hosted by systemd.

I'm using it as auto deploy my django code
running by a uwsgi server.

to build it:
(run as yourself)
./configure
(run as root)
sudo make

Then the binary reload-deploy is what you need
