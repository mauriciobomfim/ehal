input metauml;

Class.port("port") ()
(	"+ write (id : u08, mask : port_t, val : port_t) : void",
	"+ read (id : u08) : port_t",

	"+ set_dir (id : u08, mask : port_t, val : port_t) : void",
	"+ get_dir (id : u08) : port_t",

	"+ set_pullup (id : u08, val : port_t) : void",
	"+ get_pullup (id : u08) : port_t",

	"+ validate (id : u08) : u08",
);

Class.pin("pin") ()
(	"+ init (port : u08, pin : u08) : pin_t",
	"+ validate (pin_t p) : u08",

	"+ high (p : pin_t) : void",
	"+ low (p : pin_t) : void",
	"+ getvalue (p : pin_t) : u08",

	"+ in (p : pin_t) : void",
	"+ out (p : pin_t) : void",
	"+ getdir (p : pin_t) : u08",

	"+ pullup (p : pin_t) : void",
	"+ nopullup (p : pin_t) : void",
	"+ getpullup (p : pin_t) : u08",
);

Class.usart("usart") ()
(	"+ init (id : u08, freq : u32, cpu_freq : u32) : void",
	"+ validate (id : u08) : bool",
);

beginfig(1);
leftToRight (05)(port, pin);
drawObjects (port, pin);
endfig;

end
