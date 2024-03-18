{
    "targets": [
        {
            'target_name': 'krp-sharedmemory-client-native',
            'sources': [
                'src/KRPSMC.cpp',
                'src/MappedBuffer/MappedBuffer.cpp',
                'src/Controller/BaseInfo/BaseInfo.cpp',
                'src/Controller/PluginInfo/PluginInfo.cpp',
                'src/Controller/KartEventInfo/KartEventInfo.cpp',
                'src/Controller/KartSessionInfo/KartSessionInfo.cpp',
                'src/Controller/KartTelemetryInfo/KartTelemetryInfo.cpp',
                'src/Controller/KartLapsInfo/KartLapsInfo.cpp',
                'src/Controller/KartSplitsInfo/KartSplitsInfo.cpp',
                'src/Controller/TrackSegmentsInfo/TrackSegmentsInfo.cpp',
                'src/Controller/RaceEventInfo/RaceEventInfo.cpp',
                'src/Controller/RaceEntriesInfo/RaceEntriesInfo.cpp',
                'src/Controller/RaceSessionInfo/RaceSessionInfo.cpp',
                'src/Controller/RaceLapsInfo/RaceLapsInfo.cpp',
                'src/Controller/RaceSplitsInfo/RaceSplitsInfo.cpp',
                'src/Controller/RaceSpeedsInfo/RaceSpeedsInfo.cpp',
                'src/Controller/RaceCommunicationsInfo/RaceCommunicationsInfo.cpp',
                'src/Controller/RaceClassificationInfo/RaceClassificationInfo.cpp',
                'src/Controller/RaceTrackPositionsInfo/RaceTrackPositionsInfo.cpp',
                'src/Controller/RaceVehiclesDataInfo/RaceVehiclesDataInfo.cpp',
                'src/Controller/CamerasInfo/CamerasInfo.cpp',
                'src/Controller/CamerasControlInfo/CamerasControlInfo.cpp',
            ],
            'dependencies': ["<!(node -p \"require('node-addon-api').targets\"):node_addon_api_except"],
            "cflags_cc": ["-std=c++17"],
            'msvs_settings': {
                'VCCLCompilerTool': {
                    'AdditionalOptions': [ '-std:c++17', ]
                },
            }
        }
    ]
}