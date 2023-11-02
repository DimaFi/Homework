using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram
{
    struct SPoint
    {
        public int x, y, z;

        public SPoint(int x, int y, int z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public void Show()
        {
            Console.WriteLine("({0}, {1}, {2})", x, y, z);
        }

        public double Distance(SPoint other)
        {
            int dx = other.x - x;
            int dy = other.y - y;
            int dz = other.z - z;
            return Math.Sqrt(dx * dx + dy * dy + dz * dz);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inputFile = new StreamReader("input.txt");

            SPoint[] points;

            int numPoints = int.Parse(inputFile.ReadLine());
            points = new SPoint[numPoints];

            for (int i = 0; i < numPoints; i++)
            {
                string[] coords = inputFile.ReadLine().Split(new char[] { ' ', '\n', '\t' });
                int x = int.Parse(coords[0]);
                int y = int.Parse(coords[1]);
                int z = int.Parse(coords[2]);
                points[i] = new SPoint(x, y, z);
            }

            inputFile.Close();

            List<SPoint> minPoints = PointsMinDistance(points);

            StreamWriter outputFile = new StreamWriter("output.txt");

            for (int i = 0; i < points.Length; i++)
            {
                double summary = 0;
                outputFile.WriteLine($"Distances from point {i}:");
                for (int j = 0; j < points.Length; j++)
                {
                    if (i != j)
                    {
                        double distance = points[i].Distance(points[j]);
                        summary += distance;
                        outputFile.WriteLine($"To point {j}: {distance}");
                    }
                }
                outputFile.WriteLine($"Summary: {summary}");
                outputFile.WriteLine();
            }

            outputFile.WriteLine("Points min sum:");
            foreach (var point in minPoints)
            {
                outputFile.WriteLine($"{point.x} {point.y} {point.z}");
            }

            outputFile.Close();
        }

        static List<SPoint> PointsMinDistance(SPoint[] points)
        {
            double minSumDistance = double.MaxValue;
            List<SPoint> minPoints = new List<SPoint>();

            for (int i = 0; i < points.Length; i++)
            {
                double sumDistance = 0;

                for (int j = 0; j < points.Length; j++)
                {
                    if (i != j)
                    {
                        sumDistance += points[i].Distance(points[j]);
                    }
                }

                if (sumDistance == minSumDistance)
                {
                    minPoints.Add(points[i]);
                }
                else if (sumDistance < minSumDistance)
                {
                    minPoints.Clear();
                    minPoints.Add(points[i]);
                    minSumDistance = sumDistance;
                }
            }

            return minPoints;
        }
    }
}



6
1 1 1
-1 -1 -1
2 2 2
-2 -2 -2
3 3 3
4 4 4
