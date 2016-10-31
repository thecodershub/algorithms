-module(bubblesort).
-include_lib("eunit/include/eunit.hrl").

-export([start/0]).

% Bubblesort implementation in Erlang
% https://en.wikipedia.org/wiki/Bubblesort

bubblesort(ToBeSorted) ->
  bubblesort(ToBeSorted, [], true).

% When receiving an empty list, sorting is done
% Return the accumulator list reversed
bubblesort([], Acc, true) -> lists:reverse(Acc);
bubblesort([], Acc, false) ->
  bubblesort(lists:reverse(Acc), [], true);
bubblesort([X, Y | T], Acc, _Done ) when X > Y ->
  bubblesort( [X | T], [Y | Acc], false );
bubblesort([X | T], Acc, Done ) ->
  bubblesort( T, [X | Acc], Done ).

start() ->
  Test1 = [4, 1, 2, 3, 9],
  Test2 = [1],
  Test3 = [2, 2, 1, -1, 0, 4, 5, 2],
  Test4 = [],
  ?assert(bubblesort(Test1) =:= [1,2,3,4,9]),
  ?assert(bubblesort(Test2) =:= [1]),
  ?assert(bubblesort(Test3) =:= [-1,0,1,2,2,2,4,5]),
  ?assert(bubblesort(Test4) =:= []).
