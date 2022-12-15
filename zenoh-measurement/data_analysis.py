import pandas as pd
import math
import matplotlib.pyplot as plt
# calculate seconds for sent
def get_processed_df(received_data_path: str, sent_data_path: str) -> pd.DataFrame:
    """
    Get processed dataframe for a run.  
    It will merge sent and received json files and calculate seconds for sent packets.
    """
    sent_df = pd.read_json(sent_data_path)
    received_df = pd.read_json(received_data_path)
    
    sent_df = pd.json_normalize(sent_df['sent_packet_list'])
    received_df = pd.json_normalize(received_df['received_packet_list'])
    sent_df['second'] = (sent_df['sent_time'] - sent_df['sent_time'].iloc[0]) / 100
    sent_df['second'] = sent_df['second'].apply(lambda x: math.floor(x))
    sent_df['packet_id'] = sent_df['packet_id'].astype(int)
    received_df['packet_id'] = received_df['packet_id'].astype(int)
    sent_received = pd.merge(sent_df, received_df, how='left', left_on='packet_id', right_on='packet_id')
    sent_received['delay'] = sent_received['received_time'] - sent_received['sent_time']
    return sent_received

def get_stats_values(df: pd.DataFrame) -> None:
    """
    Get stats values for a run. It returns total sent packets, total received packets, total lost packets, total lost packets percentage, average delay.
    """
    total_sent_packets = df.shape[0]
    total_received_packets = df[df['received_time'].notnull()].shape[0]
    print(f"Total sent packets: {total_sent_packets}")
    print(f"Total received packets: {total_received_packets}")
    print(f"Total lost packets: {total_sent_packets - total_received_packets}")
    print(f"Total lost packets percentage: {(total_sent_packets - total_received_packets) / total_sent_packets * 100}%")
    print(f"Average delay: {df['delay'].mean()} ms")

def draw_recieved_packet_line_chart(second_received_packets_lists, payload_size, drop_rate):
    # second_received_packets_lists is a list of list, we want to calculate the max second count
    max_second_count = 0
    for second_received_packets_list in second_received_packets_lists:
        if len(second_received_packets_list) > max_second_count:
            max_second_count = len(second_received_packets_list)
            
    print(f"Max second count: {max_second_count}")
    # create a list of size max_second_count, and each element is average of the same second in every list
    result = []
    for i in range(max_second_count):
        total_received_packets = 0
        for second_received_packets_list in second_received_packets_lists:
            if i < len(second_received_packets_list):
                total_received_packets += second_received_packets_list[i]
        result.append(total_received_packets / len(second_received_packets_lists))

    # plot the average line chart
    plt.plot(result)
    plt.xlabel('seconds (in 100ms)')
    plt.ylabel('received packets')
    plt.title(f"Average received packets in every second for {payload_size}kb_drop_{drop_rate}")
    plt.show()

if __name__ == "__main__":
    # define a dictionary to indicate every scenario
    payload_size_list = [1, 10]
    drop_rate_list = [0, 1, 3, 5]
    run_list = [1, 2, 3]
    for payload_size in payload_size_list:
        for drop_rate in drop_rate_list:
            current_scenario = [0, 0, 0] # first element is total sent packets, second element is total received packets, third element is average delay
            second_received_packets_lists = []
            for run in run_list:
                df = get_processed_df(
                    received_data_path=f"received-data/{payload_size}kb_drop_{drop_rate}_{run}.json",
                    sent_data_path=f"sent-data/{payload_size}kb_drop_{drop_rate}_{run}.json"
                )
                current_scenario[0] += df.shape[0]
                current_scenario[1] += df[df['received_time'].notnull()].shape[0]
                current_scenario[2] += df['delay'].mean()
                second_received_packets_list = []
                print(df)
                for second in range(df['second'].max() + 1):
                    second_df = df[df['second'] == second]
                    second_received_packets = second_df[second_df['received_time'].notnull()].shape[0]
                    second_received_packets_list.append(second_received_packets)
                second_received_packets_lists.append(second_received_packets_list)
            # draw line chart for average received packets in every second
            draw_recieved_packet_line_chart(second_received_packets_lists, payload_size, drop_rate)
            # calculate total lost packets and total lost packets percentage
            current_scenario[0] = current_scenario[0] / 3
            current_scenario[1] = current_scenario[1] / 3
            current_scenario[2] = current_scenario[2] / 3
            print(f"For scenario {payload_size}kb_drop_{drop_rate}:")
            print(f"Total Average sent packets: {current_scenario[0]}")
            print(f"Total Average received packets: {current_scenario[1]}")
            print(f"Total Average lost packets: {current_scenario[0] - current_scenario[1]}")
            print(f"Total Average lost packets percentage: {(current_scenario[0] - current_scenario[1]) / current_scenario[0] * 100}%")
            print(f"Total Average delay: {current_scenario[2]} ms")
            print("")
