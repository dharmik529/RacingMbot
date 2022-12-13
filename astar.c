package a_star.c.simple;

import java.util.Arrays;

/**
 * Used to perform the A-Star (A*) Algorithm to find the shortest path from a start to a target node.
 */
/**
 * Finds the shortest distance between two nodes using the A-star algorithm
 * @param graph an adjacency-matrix-representation of the graph where (x,y) is the weight of the edge or 0 if there is no edge.
 * @param heuristic an estimation of distance from node x to y that is guaranteed to be lower than the actual distance. E.g. straight-line distance
 * @param start the node to start from.
 * @param goal the node we're searching for
 * @return The shortest distance to the goal node. Can be easily modified to return the path.
 * */
public class AStar {
    public static double aStar(int[][] graph, double[][] heuristic, int start, int goal) {
        int[] distances = new int[graph.length];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[start] = 0;
        double[] priorities = new double[graph.length]; //costs calculated with heurisitc
        Arrays.fill(priorities, Integer.MAX_VALUE);
        //start node has a priority equal to straight line distance to goal. It will be the first to be expanded.
        priorities[start] = heuristic[start][goal];
        //This contains whether a node was already visited
        boolean[] visited = new boolean[graph.length];
        //While there are nodes left to visit
        while (true) {
            //find the node with the currently lowest priority
            double lowestPriority = Integer.MAX_VALUE;
            int lowestPriorityIndex = -1;
            for (int i = 0; i < priorities.length; i++) {
                //... by going through all nodes that haven't been visited yet
                if (priorities[i] < lowestPriority && !visited[i]) {
                    lowestPriority = priorities[i];
                    lowestPriorityIndex = i;
                }
            }
            if (lowestPriorityIndex == -1) {
                // There was no node not yet visited --> Node not found
                return -1;
            } else if (lowestPriorityIndex == goal) {
                // Goal node found
                System.out.println("Goal node found!");
                return distances[lowestPriorityIndex];
            }
            //for all neighboring nodes that haven't been visited yet
            for (int i = 0; i < graph[lowestPriorityIndex].length; i++) {
                if (graph[lowestPriorityIndex][i] != 0 && !visited[i]) {
                    //...if the path over this edge is shorter...
                    if (distances[lowestPriorityIndex] + graph[lowestPriorityIndex][i] < distances[i]) {
                        //...save this path as new shortest path
                        distances[i] = distances[lowestPriorityIndex] + graph[lowestPriorityIndex][i];
                        //...and set the priority with which we should continue with this node
                        priorities[i] = distances[i] + heuristic[i][goal];
                        System.out.println("Updating distance of node " + i + " to " + distances[i] + " and priority to " + priorities[i]);
                    }
                }
            }
            // Lastly, note that we are finished with this node.
            visited[lowestPriorityIndex] = true;
        }
    }
}
//System.out.println("Visiting node " + lowestPriorityIndex + " with currently lowest priority of " + lowestPriority);
//System.out.println("Visited nodes: " + Arrays.toString(visited));
//System.out.println("Currently lowest distances: " + Arrays.toString(distances));
