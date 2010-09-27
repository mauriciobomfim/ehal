input metauml;

Class.port("port") ()
(	"+ write (id : u08, mask : port_t, value : port_t) : void",
	"+ read (id : u08) : port_t",
	"+ set_dir (id : u08, mask : port_t, value : port_t) : void",
	"+ get_dir (id : u08) : pio_t",
);

Class.pin("pin") ()
(	"+ init (port : u08, pin : u08) : pio_t",
	"+ high (p : pio_t) : void",
	"+ low (p : pio_t) : void",
	"+ in (p : pio_t) : void",
	"+ out (p : pio_t) : void",
	"+ pullup (p : pio_t) : void",
	"+ nopullup (p : pio_t) : void",
	"+ get (p : pio_t) : bool",
);

Class.usart("usart") ()
(	"+ init (id : u08, freq : u32, cpu_freq : u32) : void",
	"+ send (id : u08, data : u08) : void",
	"+ recv (id : u08, *data : char) : u08",
	"+ validate (id : u08) : bool",
);

beginfig(1);
topToBottom (45)(port, pin);
drawObjects (port, pin);
endfig;

end
