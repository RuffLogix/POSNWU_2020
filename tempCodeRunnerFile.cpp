    if(dist[x.first] > dist[u] + x.second){
                    if(x.first==d)ans = max(ans,a);  

                    dist[x.first] = dist[u] + x.second;
                    q.push({dist[x.first],{x.first,min(a,x.second)}});
                }