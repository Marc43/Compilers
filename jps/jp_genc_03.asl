func i_dotprod(x : array[10] of int,
               y : array[10] of int) : int
  return x*y;
endfunc
  
func f_dotprod(x : array[10] of float,
               y : array[10] of float) : float
  return x*y;
endfunc

func i_readvec(x : array[10] of int)
  var i : int
  i = 0;
  while i<10 do
    read x[i];
    i = i+1;
  endwhile
endfunc

func f_readvec(x : array[10] of float)
  var i : int
  i = 0;
  while i<10 do
    read x[i];
    i = i+1;
  endwhile
endfunc

func main()
  var a : array[10] of int
  var b : array[10] of int
  var c : array[10] of float
  var d : array[10] of float
  
  // omplir vectors
  i_readvec(a); i_readvec(b); f_readvec(c); f_readvec(d);
  
  // calcular producte escalar dins una funcio
  write "dotprod int funcio = ";
  write i_dotprod(a,b);
  write "\n";
  write "dotprod float funcio = ";
  write f_dotprod(c,d);
  write "\n";

  // calcular producte escalar de vectors locals
  write "dotprod int local = ";
  write a*b;
  write "\n";
  write "dotprod float local = ";
  write c*d;
  write "\n";
endfunc
