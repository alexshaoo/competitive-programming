import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

// rename class to 'Main' when submitting
public class s3 {
	
	// Maximum number of vertices in the graph
	private int maxNumVertices = 50;
	
	// Which nodes has been traversed yet
	boolean[] visited;
	
	LinkedList<Integer>[] adj;
	
	// For modified BFS
	int[] previous = new int[maxNumVertices];
	
	int[] distance = new int[maxNumVertices];
		
	// Usually make nodes, add edges later
	public s3(int initialNodes) {
		
		// 0 to 50 inclusive
		adj = new LinkedList[maxNumVertices];
		visited = new boolean[maxNumVertices];
		
		// Initialize list for each node
		for (int i = 1; i < maxNumVertices; i++) {
			adj[i] = new LinkedList<>();
		}
		
		makeFriend(1, 6);
		
		makeFriend(2, 6);
		
		makeFriend(3, 4);
		makeFriend(3, 5);
		makeFriend(3, 6);
		makeFriend(3, 15);
		
		makeFriend(4, 5);
		makeFriend(4, 6);
		
		makeFriend(5, 6);
		
		makeFriend(6, 7);
		
		makeFriend(7,  8);
		
		makeFriend(8,  9);
		
		makeFriend(9, 10);
		makeFriend(9, 12);
		
		makeFriend(10, 11);
		
		makeFriend(11, 12);
		
		makeFriend(12, 13);
		
		makeFriend(13, 14);
		makeFriend(13, 15);
		
		makeFriend(16, 17);
		makeFriend(16, 18);
		
		makeFriend(17, 18);
	}
	
	// Create undirected edge between two people
	public void makeFriend(int person1, int person2) {
		
		adj[person1].add(person2);
		adj[person2].add(person1);
	}
	
	// Destroy edge between two friends
	public void removeFriend(int person1, int person2) {
		
		adj[person1].remove((Integer) person2);
		adj[person2].remove((Integer) person1);
	}
	
	// Number of the friends of friends
	public void FOF(int person) {
		
		int num = 0;
		
		visited[person] = true;
		
		ArrayList<Integer> friends = new ArrayList<>();
		
		for (int friend : adj[person]) {
			friends.add(friend);
			visited[friend] = true;
		}
		
		while (!friends.isEmpty()) {
			int friend = friends.remove(0);
			
			for (int friendOfFriend : adj[friend]) {
				
				if (!visited[friendOfFriend]) {
					
					num++;
					visited[friendOfFriend] = true;
				}
			}
		}
		
		visited = new boolean[maxNumVertices];
		
		System.out.println(num);
	}
	
	public boolean BFS(int person1, int person2) {
		
		LinkedList<Integer> q = new LinkedList<>();
			
		for (int i = 0; i < maxNumVertices; i++) {
			
			distance[i] = Integer.MAX_VALUE;
			previous[i] = -1;
		}
		
		visited[person1] = true;
		distance[person1] = 0;
		
		q.add(person1);
		
		while (!q.isEmpty()) {
			
			int friend = q.poll();
			visited[friend] = true;
			
			for (int i = 0; i < adj[friend].size(); i++) {
				if (!visited[adj[friend].get(i)]) {
					
					visited[adj[friend].get(i)] = true;
					distance[adj[friend].get(i)] = distance[friend] + 1;
					previous[adj[friend].get(i)] = friend;
					q.add(adj[friend].get(i));
					
					if (adj[friend].get(i) == person2) {
						
						return true;
					}
					
				}
				
			}
			
		}
		
		return false;
	}
	
	public void DOS(int person1, int person2) {
	
		if (!BFS(person1, person2)) {
			System.out.println("Not connected");
		} else {
			
			LinkedList<Integer> path = new LinkedList<>();
			
			int crawl = person2;
			
			path.add(crawl);
			
			while (previous[crawl] != -1) {
				
				path.add(previous[crawl]);
				
				crawl = previous[crawl];
			}
			
			
			System.out.println(path.size() - 1);
		}
		
		previous = new int[maxNumVertices];
		distance = new int[maxNumVertices];
		visited = new boolean[maxNumVertices];
	}
	

	public static void main(String[] args) {
		
        s3 g = new s3(18);
        
        Scanner sc = new Scanner(System.in);
        
        String command = sc.next();
        
        //g.printGraph();
        
        while (!command.equals("q")) {
        	
        	if (command.equals("i")) {
        		
        		int x = sc.nextInt();
        		int y = sc.nextInt();
        		
        		g.makeFriend(x, y);
        	} else if (command.equals("d")) {
        		
        		int x = sc.nextInt();
        		int y = sc.nextInt();
        		
        		g.removeFriend(x, y);
        	} else if (command.equals("n")) {
        		
        		int x = sc.nextInt();
        		System.out.println(g.adj[x].size());
        		
        	} else if (command.equals("f")) {
        		
        		int x = sc.nextInt();
        		
        		g.FOF(x);
        	} else if (command.equals("s")) {
        		
        		int x = sc.nextInt();
        		int y = sc.nextInt();
        		
        		g.DOS(x, y);
        		
        		
        	}
        	
        	command = sc.next();
        	
        }
        
	}

}