TOLR = main.o welcome.o login.o register.o user.h
Tologin=tolr
$(Tologin): $(TOLR)
	gcc -o $(Tologin) $(TOLR)

main.o: main.c

welcome.o: welcome.c welcome.h

login.o: login.c login.h user.h

register.o: register.c register.h user.h

clean:
	rm -f $(Tologin) $(TOLR)