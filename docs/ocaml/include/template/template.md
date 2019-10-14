---
title: "template.ml"
---
- [GitHub]({{ site.github.repository_url }}/blob/master/ocaml/include/template/template.ml)

{% highlight ocaml %}
module A = Array
module C = Char
module I = Int64
module L = List
module Q = Queue

let pf = Printf.printf

let read_int () = Scanf.scanf "%d " (fun x -> x)
let read_float () = Scanf.scanf "%f " (fun x -> x)
let read_string () = Scanf.scanf "%s " (fun x -> x)
let read_array read n = A.init n (fun _ -> read ())

let range s t = A.init (t - s) @@ (+) s
let foreach fold_f init s t map_f =
  range s t |> A.map map_f |> A.fold_left fold_f init

module S = struct
  include String
  let of_array a = String.init (A.length a) (A.get a)
  let to_array s = A.init (String.length s) (String.get s)
end;;
{% endhighlight %}

[Back](../..)
