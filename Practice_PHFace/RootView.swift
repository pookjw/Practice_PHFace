//
//  RootView.swift
//  Practice_PHFace
//
//  Created by Jinwoo Kim on 7/9/23.
//

import SwiftUI
import Photos

struct RootView: View {
    var body: some View {
        NavigationSplitView {
            FacesView()
                .viewController { viewController in
                    guard let splitViewController: UISplitViewController = viewController.splitViewController else {
                        return
                    }
                    
                    splitViewController.displayModeButtonVisibility = .never
                }
        } detail: {
            
        }
        .onAppear {
            PHPhotoLibrary.requestAuthorization(for: .readWrite) { status in
                assert(status == .authorized)
            }
        }
    }
}

#Preview {
    RootView()
}
