## dijkstra.ml

- [GitHub]({{ site.github.repository_url }}/blob/master/ocaml/include/graph/dijkstra.ml)

### Includes

- [typeinfo.ml](../template/typeinfo)

{% highlight ocaml %}
type 'a edge = { s : int; t : int; cost : 'a }
type 'a graph = 'a edge list array

let add_edge g s t c =
  let e = { s = s; t = t; cost = c } in
  g.(s) <- e :: g.(s)

let dijkstra ty g s =
  let n = Array.length g in
  let dist = Array.make n ty.inf in
  dist.(s) <- ty.zero;
  let open BatHeap in
  let que = ref (of_list [(ty.zero, s)]) in
  let update v e =
    let nd = ty.add dist.(v) e.cost in
    if dist.(e.t) > nd
    then (dist.(e.t) <- nd; que := insert !que (nd, e.t)) in
  while size !que > 0 do
    let d, v = find_min !que in
    que := del_min !que;
    if dist.(v) = d
    then List.iter (update v) g.(v)
  done; dist
{% endhighlight %}

[Back](../..)
