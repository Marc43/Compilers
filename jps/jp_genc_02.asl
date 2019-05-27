func dotprod(x : array[10] of float,
             y : array[10] of float) : float
  var i : int
  var s : float
  i = 0;
  s = 0;
  while i < 10 do
    s = s + x[i]*y[i];
    i = i+1;
  endwhile
  return s;
endfunc

func main()
  var a : array[10] of float
  var b : array[10] of float
  var i : int
  
  // omplir vectors
  // a = [0.4,0.8,1.2,1.6,2,2.4,2.8,3.2,3.6,4]
  // b = [7,6.3,5.6,4.9,4.2,3.5,2.8,2.1,1.4,0.7]
  i = 0;
  while i<10 do
    a[i] = (i+1)/2.5;  
    b[9-i]=(i+1)*0.7;
    i = i+1;
  endwhile
  
  // calcular producte escalar "manualment"
  write "dotprod manual = ";
  write dotprod(a,b);
  write "\n";

  // calcular producte escalar amb nou operador
  write "dotprod operador = ";
  write a*b;
  write "\n";
endfunc
