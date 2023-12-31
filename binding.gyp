{
  'targets': [
    {
      'target_name': 'krp-sharedmemory-client-native',
      'sources': [
          'src/krp_sharedmemory_client.cpp',
          'src/SharedFileIn.h',
          'src/SharedFileOut.h',
          'src/MappedBuffer.h',
          'src/MappedBuffer.cpp',
          'src/Utils.h',
          'src/Utils.cpp',
          'src/PluginInfo.h',
          'src/PluginInfo.cpp',
          'src/KartEventInfo.h',
          'src/KartEventInfo.cpp',
          'src/KartSessionInfo.h',
          'src/KartSessionInfo.cpp',
            'src/KartLapInfo.h',
            'src/KartLapInfo.cpp',
            'src/KartSplitInfo.h',
            'src/KartSplitInfo.cpp',
            'src/KartTelemetryInfo.h',
            'src/KartTelemetryInfo.cpp',
            'src/TrackSegmentInfo.h',
            'src/TrackSegmentInfo.cpp',
            'src/RaceEventInfo.h',
            'src/RaceEventInfo.cpp',
            'src/RaceEntriesInfo.h',
            'src/RaceEntriesInfo.cpp',
            'src/RaceAddEntryInfo.h',
            'src/RaceAddEntryInfo.cpp',
            'src/RaceRemoveEntryInfo.h',
            'src/RaceRemoveEntryInfo.cpp',
            'src/RaceSessionInfo.h',
            'src/RaceSessionInfo.cpp',
            'src/RaceSessionStateInfo.h',
            'src/RaceSessionStateInfo.cpp',
            'src/RaceLapInfo.h',
            'src/RaceLapInfo.cpp',
            'src/RaceSplitInfo.h',
            'src/RaceSplitInfo.cpp',
            'src/RaceSpeedInfo.h',
            'src/RaceSpeedInfo.cpp',
            'src/RaceCommunicationInfo.h',
            'src/RaceCommunicationInfo.cpp',
            'src/RaceClassificationInfo.h',
            'src/RaceClassificationInfo.cpp',
            'src/RaceTrackPositionInfo.h',
            'src/RaceTrackPositionInfo.cpp',
            'src/RaceVehicleDataInfo.h',
            'src/RaceVehicleDataInfo.cpp',
            'src/PluginInfoWorker.h',
            'src/PluginInfoWorker.cpp',
            'src/KartEventInfoWorker.h',
              'src/KartEventInfoWorker.cpp',
              'src/KartSessionInfoWorker.h',
              'src/KartSessionInfoWorker.cpp',
              'src/KartLapInfoWorker.h',
              'src/KartLapInfoWorker.cpp',
              'src/KartSplitInfoWorker.h',
              'src/KartSplitInfoWorker.cpp',
              'src/KartTelemetryInfoWorker.h',
              'src/KartTelemetryInfoWorker.cpp',
              'src/TrackSegmentInfoWorker.h',
              'src/TrackSegmentInfoWorker.cpp',
              'src/RaceEventInfoWorker.h',
              'src/RaceEventInfoWorker.cpp',
              'src/RaceEntriesInfoWorker.h',
              'src/RaceEntriesInfoWorker.cpp',
              'src/RaceAddEntryInfoWorker.h',
              'src/RaceAddEntryInfoWorker.cpp',
              'src/RaceRemoveEntryInfoWorker.h',
              'src/RaceRemoveEntryInfoWorker.cpp',
              'src/RaceSessionInfoWorker.h',
              'src/RaceSessionInfoWorker.cpp',
              'src/RaceSessionStateInfoWorker.h',
              'src/RaceSessionStateInfoWorker.cpp',
              'src/RaceLapInfoWorker.h',
              'src/RaceLapInfoWorker.cpp',
              'src/RaceSplitInfoWorker.h',
              'src/RaceSplitInfoWorker.cpp',
              'src/RaceSpeedInfoWorker.h',
              'src/RaceSpeedInfoWorker.cpp',
              'src/RaceCommunicationInfoWorker.h',
              'src/RaceCommunicationInfoWorker.cpp',
              'src/RaceClassificationInfoWorker.h',
              'src/RaceClassificationInfoWorker.cpp',
              'src/RaceTrackPositionInfoWorker.h',
              'src/RaceTrackPositionInfoWorker.cpp',
              'src/RaceVehicleDataInfoWorker.h',
              'src/RaceVehicleDataInfoWorker.cpp',
              'src/CameraInfo.h',
              'src/CameraInfo.cpp',
              'src/CameraInfoWorker.h',
              'src/CameraInfoWorker.cpp',
              'src/CameraSet.h',
              'src/CameraSet.cpp',
      ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      "cflags_cc": ["-std=c++17"],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': {
            'ExceptionHandling': 1,
            'AdditionalOptions': [ '-std:c++17', ]
         },
      }
    }
  ]
}