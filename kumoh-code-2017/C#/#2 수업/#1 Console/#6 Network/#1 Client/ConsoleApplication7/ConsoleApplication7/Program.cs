﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
To be coded
 */
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace EchoClient
{
    class Program
    {
        static void Main(string[] args)
        {
            byte[] data = new byte[1024];
            string input, stringData;
            // To be coded (Hint: Declare TcpClient Variable - 변수명: server)
            TcpClient server;

            try
            {
                // To be coded (Hint: Connect to Server)
                //server.Connect("202.31.138.149", 1111);
                server = new TcpClient("202.31.138.149", 1111);
            }
            catch (SocketException)
            {
                Console.WriteLine("Unable to connect to server");
                return;
            }

            // Read Hello Message
            // To be coded (Hint: Make NetworkStream from server - 변수명: ns)
            NetworkStream ns = server.GetStream();
            int recv = ns.Read(data, 0, data.Length);
            Console.WriteLine(Encoding.ASCII.GetString(data, 0, recv));

            while (true)
            {
                // Type Message for sending
                input = Console.ReadLine();
                if ("exit" == input)
                    break;

                // Send Message to Server
                // To be coded (Hint: Encoding.ASCII.GetBytes(input))
                ns.Write(Encoding.ASCII.GetBytes(input), 0, input.Length);

                recv = ns.Read(data, 0, data.Length);
                stringData = Encoding.ASCII.GetString(data, 0, recv);
                Console.WriteLine("> Echo: " + Encoding.ASCII.GetString(data, 0, recv));
            }

            Console.WriteLine("Disconnecting from server ...");
            // To be coded (Hint: Close Network Stream)
            // To be coded (Hint: Close TCP Connection)
            ns.Close();
            server.Close();
        }
    }
}