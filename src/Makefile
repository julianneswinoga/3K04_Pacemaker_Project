include makefile.conf
NAME=main
STARTUP_DEFS=-D__NO_SYSTEM_INIT

LDSCRIPTS=-L. -L$(BASE)/ldscripts -T gcc.ld
LFLAGS=$(USE_NANO) $(USE_SEMIHOST) $(LDSCRIPTS) $(GC) $(MAP)

$(NAME)-$(CORE).axf: $(NAME).cpp $(STARTUP)
	$(CXX) $^ $(CXXFLAGS) -fno-exceptions $(LFLAGS) -I$(HEADERS) -o $@

clean: 
	rm -f $(NAME)*.axf *.map
