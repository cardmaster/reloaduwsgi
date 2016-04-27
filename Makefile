include myid.mk
reload-deploy: reloadwsgi
	cp -f $< $@	
	chmod 4711 $@
	
reloadwsgi: reloadwsgi.c
	gcc -o $@ -DOPERATOR_ID=$(MY_UID) $<

clean:
	rm reloadwsgi reload-deploy

install: reload-deploy
	install -m 4711 $< /usr/bin/reload-uwsgi
	
