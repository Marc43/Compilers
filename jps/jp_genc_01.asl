func dotprod(x : array[10] of int,
             y : array[10] of int) : int
  var i,s : int
  i = 0;
  s = 0;
  while i < 10 do
    s = s + x[i]*y[i];
    i = i+1;
  endwhile
  return s;
endfunc

func main()
  var a : array[10] of int
  var b : array[10] of int
  var i : int
  
  // omplir vectors
  //  a = [1,2,3,4,5,6,7,8,9,10]
  //  b = [20,18,16,14,12,10,8,6,4,2]
  i = 0;
  while i<10 do
    a[i]=i+1;       
    b[9-i]=(i+1)*2; 
    i = i+1;
  endwhile
  
  // calcular producte escalar "manualment"
  write "dotprod manual = ";
  write dotprod(a,b);
  write "\n";

  // calcular producte escalar amb la nova operació
  write "dotprod operador = ";
  write a*b;
  write "\n";
endfunc
