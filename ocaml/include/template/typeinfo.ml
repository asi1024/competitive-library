type 't typeinfo =
  { zero : 't;
    one  : 't;
    inf  : 't;
    add  : 't -> 't -> 't;
    sub  : 't -> 't -> 't;
    mul  : 't -> 't -> 't; }

let int_info = {
    zero = 0;
    one  = 1;
    inf  = int_of_float 1e18;
    add  = (+);
    sub  = (-);
    mul  = ( * ) }

let float_info = {
    zero = 0.;
    one  = 1.;
    inf  = 1e18;
    add  = (+.);
    sub  = (-.);
    mul  = ( *. ) }
