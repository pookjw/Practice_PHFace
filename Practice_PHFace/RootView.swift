//
//  RootView.swift
//  Practice_PHFace
//
//  Created by Jinwoo Kim on 7/9/23.
//

import SwiftUI
import Photos

struct RootView: View {
    @State private var selectedPHPerson: PHPerson?
    
    var body: some View {
        NavigationSplitView {
            PeopleView(selectedPHPerson: $selectedPHPerson)
                .viewController { viewController in
                    guard let splitViewController: UISplitViewController = viewController.splitViewController else {
                        return
                    }
                    
                    splitViewController.displayModeButtonVisibility = .never
                }
        } detail: {
            if let selectedPHPerson: PHPerson {
                PersonView(phPerson: selectedPHPerson)
            }
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
